#ifndef ABBI_H
#define ABBI_H 1

#include "noABBI.h"

typedef struct aBBI
{
    NoABBI *raiz;
    int nroNos;
    
 } ABBI;

 ABBI *criarABBI();

void inserirABBI(int chave, ABBI *pontABBI);

 #endif;

