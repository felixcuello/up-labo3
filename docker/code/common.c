#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>

key_t create_key() {
    key_t key = ftok("/tmp", 42);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }
    return key;
}
