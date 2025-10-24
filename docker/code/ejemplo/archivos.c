#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "archivos.h"
#include "def.h"

FILE *ptrFile; /*se puede/debe declarar el puntero para el uso de archivos, global de archivo*/

int inAbrirArchivo(char *szNombreArchivo,char *szModo) {
	ptrFile=fopen(szNombreArchivo,szModo);
	if(ptrFile==NULL)
		return FALSE;
	return TRUE;
}

int inLeerArchivo(char *szBuffer, size_t size)
{
	/* Validación de parámetros */
	if(szBuffer == NULL || size == 0 || ptrFile == NULL)
		return FALSE;
	
	/* Usar fgets para lectura segura con límite de buffer */
	if(fgets(szBuffer, size, ptrFile) == NULL)
		return FALSE;
	
	return TRUE;
}

void voCerrarArchivo() {
	fclose(ptrFile);
}

int inEscribirArchivo(char *szDatos) {
  int inRes = 0;

  inRes = fprintf(ptrFile, "%s", szDatos);

  if(inRes < 0)
    return FALSE;

  return TRUE;
}

