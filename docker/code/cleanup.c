#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "common.h"

int main() {
    key_t key = create_key();

    int shmid = shmget(key, SIZE, 0666);
    if (shmid != -1) shmctl(shmid, IPC_RMID, NULL);

    int semid = semget(key, 1, 0666);
    if (semid != -1) semctl(semid, 0, IPC_RMID);

    printf("Cleanup complete.\n");
    return 0;
}
