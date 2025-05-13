#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

void sem_wait(int semid) {
    struct sembuf op = {0, -1, 0};
    semop(semid, &op, 1);
}

void sem_signal(int semid) {
    struct sembuf op = {0, 1, 0};
    semop(semid, &op, 1);
}

int main() {
    key_t key = create_key();

    int shmid = shmget(key, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) { perror("shmget"); exit(1); }

    char *shmaddr = (char *)shmat(shmid, NULL, 0);

    int semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid == -1) { perror("semget"); exit(1); }

    semctl(semid, 0, SETVAL, 1);

    char c;
    for(c = 'A'; c <= 'Z'; c++) {
        sem_wait(semid);
        snprintf(shmaddr, SIZE, "Writer1: %c\n", c);
        printf("Writer1 wrote: %c\n", c);
        sleep(1);
        sem_signal(semid);
        sleep(1);
    }

    shmdt(shmaddr);
    return 0;
}
