#include "funciones.h"

int main(int argc, char *argv[]) {
  int i;
  for(i=0; i<=100; i++)
    printf("%d\n", devolver_numero_aleatorio_no_repetitivo());
  return 0;
}
