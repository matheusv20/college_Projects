#include "aBBI.h"
#include "noSLI.h"

ABBI *criarABBI()
{
    ABBI *nova = (ABBI *) malloc(sizeof(ABBI));

    nova->raiz = NULL;
    nova->nroNos = 0;

    return nova;
}

void inserirABBI(int chave, ABBI *pontABBI)
{
    NoABBI *novo = criarNoABBI(5, NULL, NULL);

    if (pontABBI->nroNos == 0)
    {
        pontABBI->raiz = novo;
        pontABBI->nroNos++;
    }
    
    else
    {   
        NoABBI *pontAuxPai = NULL;
        NoABBI *pontAux = pontABBI->raiz;

        while(pontAux != NULL)
        {
            if  (chave < pontAux->chave)
            {
                pontAux = pontAux->filhoEsq;
            }

            else if (chave > pontAux->chave)
            {
                pontAux = pontAux->filhoDir;
            }
            
            else if (chave == pontAux->chave)
            {

            }

        }
    
    }
    

}