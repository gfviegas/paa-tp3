/**
 * Gerencia e chama as funções relacionadas ao problema de obras na ciade,
 * imprimindo e lendo os dados necessários
 *
 * Gustavo Viegas (3026) e Heitor Passeado (3055)
 * @author Gustavo Viegas
 */

#ifndef interfaceCity_h
#define interfaceCity_h

#define WORD_MAX_LENGTH 250

#include <stdio.h>

#include "../util/interface.h"
#include "../util/logger.h"
#include "direction.h"
#include "construction.h"
#include "road.h"

/**
 * [description]
 * @param analysisMode Flag se está no modo análise (1) ou não (0)
 */
void _cityMenu(int analysisMode);

#endif /* interfaceCity_h */
