#include <stdio.h>

int sumar(int a, int b)
{
  return a + b;
}

int restar(int a, int b)
{
  return a - b;
}

int multiplicar(int a, int b)
{
  return a * b;
}

int dividir(int a, int b)
{
  if(b == 0) {
    printf("NOPE!\n");
    return 0;
  }
  return a / b;
}

int main(int argc,char *argv[])
{
  int a,b;
  int op;

  int (*funciones[])(int, int)  = {sumar, restar, multiplicar, dividir};

  printf("0: sumar | 1: restar | 2: multiplicar | 3: dividir\n");
  scanf("%d", &op);

  printf("a=");
  scanf("%d", &a);
  printf("b=");
  scanf("%d", &b);

  printf("Resultado = %d\n", funciones[op](a, b));

  return 0;
}
