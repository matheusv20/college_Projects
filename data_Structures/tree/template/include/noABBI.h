#ifndef NOABBI_H
#define NOABBI_H 1
#include <stdlib.h>
#include <stdio.h>

typedef struct noABBI
{
    int chave;
    struct noABBI *filhoEsq;
    struct noABBI *filhoDir;

 } NoABBI;

 NoABBI *criarNoABBI(int chave, NoABBI *filhoDir, NoABBI *filhoEsq);

 #endif;

