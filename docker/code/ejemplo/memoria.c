#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  char* m = (char*)malloc(100*sizeof(char));
  memset(m, 0x00, 100*sizeof(m));
  memcpy(m, "carlos", 6);
  printf("%s\n", m);
}
