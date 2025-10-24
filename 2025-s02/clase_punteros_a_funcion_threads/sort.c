#include <stdio.h>

typedef struct {
  char nombre[50];
  int edad;
  int anio_nacimiento;
} Persona;

int comparar_por_nombre(Persona a, Persona b) {
  return a.nombre[0] < b.nombre[0];
}

int comparar_por_anio(Persona a, Persona b) {
  return a.anio_nacimiento < b.anio_nacimiento;
}

int comparar_por_edad(Persona a, Persona b) {
  return a.edad < b.edad;
}

void sort(Persona* p, int n, int(*comparar)(Persona a, Persona b)) {
  int i;
  int swap = 1;
  Persona temp;

  while(swap) {
    swap = 0;
    for(i=0; i<n-1; i++) {
      if(comparar(p[i+1], p[i])) {
        swap = 1;
        temp = p[i+1];
        p[i+1] = p[i];
        p[i] = temp;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  int i;
  int n = 5;
  Persona personas[] = {
    {"Carlos", 55, 1970},
    {"Pepe", 25, 2000},
    {"Luis", 30, 1995},
    {"Maria", 28, 1997},
    {"Ana", 20, 2005}
  };

  sort(personas, n, comparar_por_nombre);
  for(i=0; i<n; i++) {
    printf("%s , %d, %d\n", personas[i].nombre, personas[i].edad, personas[i].anio_nacimiento);
  }
}
