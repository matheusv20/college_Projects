#include "noABBI.h"

 NoABBI *criarNoABBI(int chave, NoABBI *filhoDir, NoABBI *filhoEsq)
{
    NoABBI *novo = (NoABBI *) malloc(sizeof(NoABBI));

    if (novo == NULL)
    {
        printf("Erro fatal: Falha na alocação de memoria para o NoABBI.\n");
        exit(1);
    }

    novo->chave = chave;
    novo->filhoDir = filhoDir;
    novo->filhoEsq = filhoEsq;

    return novo;
}