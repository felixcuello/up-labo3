#include <time.h>
#include <stdlib.h>

void inicializar_semilla_aleatoria() {
  srand((unsigned int)time(NULL));
}

int devolver_numero_aleatorio(int min, int max) {
  if(min >= max)
    return -1;

  return min + rand() % (max - min + 1);
}

int devolver_numero_aleatorio_no_repetitivo() {
  static int visto[101];
  int numero = devolver_numero_aleatorio(0, 100);
  int i;

  for(i=0; i<=100; i++) visto[i] = 0;
  while(visto[numero])
	numero = devolver_numero_aleatorio(0, 100);
  visto[numero] = 1;
  return numero;
}
