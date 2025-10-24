#include <string.h>
#include <stdio.h>
#include "funciones.h"
#include "archivos.h"

#define SIZE_ARCHIVO 1000

int main(/* int argc, char *argv[] */) {
  char archivo_leido[SIZE_ARCHIVO];

  inAbrirArchivo("felix.txt", "w");
  inEscribirArchivo("felix 123\n");
  inEscribirArchivo("felix 456\n");
  inEscribirArchivo("felix 678\n");
  voCerrarArchivo();

  inAbrirArchivo("felix.txt", "r");
  memset(archivo_leido, 0x00, SIZE_ARCHIVO);
  inLeerArchivo(archivo_leido, SIZE_ARCHIVO);
  voCerrarArchivo();

  printf("%s", archivo_leido);

  return 0;
}
