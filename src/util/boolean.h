/**
 * Define um tipo de dados para booleanos, para restringir apenas inteiros 1 ou 0
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */
#ifndef boolean_h
#define boolean_h

#include <stdlib.h>

typedef enum {FALSE, TRUE} boolean;

boolean toBoolean(int number);

#endif /* boolean_h */
