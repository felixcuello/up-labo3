#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define SEM_NAME "/my_init_semaphore"

// Process 1 - Must run first and initialize
int main(int argc, char *argv[]) {
    // Create or open the semaphore, initialized to 0 (locked)
    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0644, 0);
    if (sem == SEM_FAILED) {
        perror("main1: sem_open failed");
        return 1;
    }
    
    // Do initialization work here
    printf("HELLO\n");
    fflush(stdout);
    
    // Signal that initialization is complete - unlock the semaphore
    sem_post(sem);
    
    // Cleanup
    sem_close(sem);
    
    return 0;
}
