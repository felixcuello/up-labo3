#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define SEM_NAME "/my_init_semaphore"

// Process 2 - Can start anytime, but waits for main1
int main(int argc, char *argv[]) {
    // Open the semaphore (create it if it doesn't exist, still at 0)
    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0644, 0);
    if (sem == SEM_FAILED) {
        perror("main2: sem_open failed");
        return 1;
    }
    
    printf("main2: Waiting for main1 to initialize...\n");
    fflush(stdout);
    
    // Wait until main1 posts the semaphore
    sem_wait(sem);
    
    printf("main2: main1 has completed initialization, now running!\n");
    
    // Rest of main2 code runs here...
    
    // Cleanup
    sem_close(sem);
    // Note: Only one process should unlink. You could do it here or in main1
    sem_unlink(SEM_NAME);
    
    return 0;
}
