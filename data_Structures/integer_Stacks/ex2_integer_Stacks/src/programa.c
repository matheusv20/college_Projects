#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "listaSLI.h"
#include "pilhaI.h"

int expressaoCorreta(char expressao[255]);

int main()
{
    printf("%d\n", expressaoCorreta("{1 + 2 * [3 - x] + 2 * (y - z) }"));

    printf("%d\n", expressaoCorreta("{1 + 2 * [3 - x + 2 * (y - z) }"));

    printf("%d\n", expressaoCorreta("{1 + 2 * [3 - x] + 2 * (y - z)"));
}

int expressaoCorreta(char expressao[])
{   
    PilhaI *pilha = criarPilhaInt();

    int i = 0;
    int valor;
    int correta = 1;

    while (expressao[i] != '\0')
    {
        if (expressao[i] ==  '(' || expressao[i] == '[' || expressao[i] == '{')
        {
            empilharPilhaI(expressao[i], pilha);
        }

        if (expressao[i] ==  ')' || expressao[i] == ']' || expressao[i] == '}')
        {
            valor = obterTopoPilhaI(pilha);
            desempilharPilhaI(pilha);

            if (valor == '(' && expressao[i] != ')')
            {
                correta = 0;
            }

            if (valor == '[' && expressao[i] != ']')
            {
                correta = 0;
            }

            if (valor == '{' && expressao[i] != '}')
            {
                correta = 0;
            }
        }
        i++;
    }

    if (pilha->tamanho > 0)
    {
        correta = 0;
    }

    destruirPilhaI(&pilha);

    return correta;
}