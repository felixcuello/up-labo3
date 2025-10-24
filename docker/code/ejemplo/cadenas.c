#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char resultado[100];
  sprintf(resultado, "%s: %d", "felix", 48);
  printf("%s\n", resultado);
  return 0;
}
