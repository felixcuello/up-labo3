- Nunca se olviden de poner los argumentos de la función main, aunque no los usen. Siempre deben ser `int argc, char
  *argv[]` o `int argc, char **argv`.

- nunca se declaran variables en los .h
  - cuando hago `extern int x;` en un .h estoy vinculando el nombre `x` a un tipo de dato `int` en el ámbito global
- en nuestra materia podemos usar los #include con " o con < >

- JAMAS van a copiar 3 veces un mismo target de un Makefile para hacer 3 programas que hagan lo mismo

- srand() se llama UNA SOLA VEZ al principio del programa (al comienzo del main idealmente)

