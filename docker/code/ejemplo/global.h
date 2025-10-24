/*
 * En global.h se agregan las vinculaciones de las variables globales
 */
#ifndef _GLOBAL_H
#define _GLOBAL_H

extern int global_numero;
extern char global_mensaje[20+1];

typedef int mi_entero;
extern mi_entero global_mi_entero;

struct camion {
  int ruedas;
};

struct camion mercedes;


#endif
