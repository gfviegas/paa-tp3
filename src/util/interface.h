/**
 * Gerencia e chama as funções relacionadas aos puzzles, imprimindo e lendo
 * os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Heitor Passeado
 */

#ifndef interface_h
#define interface_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"
#include "../pyramid/pyramid.h"
#include "../city/interfaceCity.h"

/**
 * [prePrompt description]
 */
void prePrompt(void);

/**
 * [printMenu description]
 * @param analysisMode [description]
 */
void printMenu(int analysisMode);

/**
 * [printHeader description]
 * @param analysisMode [description]
 */
void printHeader(int analysisMode);

#endif
