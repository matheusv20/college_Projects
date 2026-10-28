#include "filaI.h"

FilaI * criarFilaI()
{
    FilaI *nova = (FilaI *) malloc(sizeof(FilaI));
    nova->tamanho = 0;
    nova->inicio = NULL;
    nova->inicio = NULL;
    return nova;
}

void limparFilaI(FilaI *pontFila)
{
    //VAZIA
    if (pontFila->tamanho == 0)
    {
        printf("Fila Vazia!");
    }

    //1 ou + DE 1 ELEMENTO
    else
    {   
        NoSLI *pontAux = pontFila->inicio; //guarda o endereço do primeiro nó

        NoSLI *pontAux2 = pontAux->proximo; //guarda o endereço do próximo nó

        while (pontAux2 != NULL)
        {
            free(pontAux); //limpou o primeiro nó
            pontAux = pontAux2; //fez o primeiro apontar para o proximo
            pontAux2 = pontAux2->proximo; //fez o próximo apontar para o outro próximo
        }
        free(pontAux); //limpou o último que ficou

        pontFila->tamanho = 0; //diminuiu o tamanho pra 0
        pontFila->inicio = NULL;
        pontFila->fim = NULL;

    }
}

void destruirFilaI(FilaI **pontPontFila)
{
    limparLSLI(*pontPontFila);
    free(*pontPontFila);
    *pontPontFila = NULL;
}

void mostrarFilaI(FilaI *pontFila)
{
    printf("Tamanho da Fila = %d\n", pontFila->tamanho); // SEMPRE MOSTRAR O TAMANHO
    
    //VAZIA

    if (pontFila->tamanho == 0)
    {
        printf("Fila Vazia\n");
    }

    // 1 OU + ELEMENTOS
    else
    {
        NoSLI *pontAux = pontFila->inicio;

        printf("%d(P) -> ", pontAux->valor);
        pontAux = pontAux->proximo;

        while (pontAux != NULL)
        {
            printf("%d -> ", pontAux->valor);
            pontAux = pontAux->proximo;
        }
        printf("NULL\n");
    }
}

void enfileirarI(int valor, FilaI *pontFila)
{
    NoSLI *novo = criarNoSLI(valor, NULL); // A mesmo passo para todas as opções

    // VAZIA
    if (pontFila->inicio == NULL) // serve os dois: (fila->tamanho == 0) ou (fila->inicio == NULL)
    {
        pontFila->inicio = novo; //B
    }

    // 1 ou + DE 1 ELEMENTO
    else
    {
        NoSLI *pontAux = pontFila->inicio;
        while (pontAux->proximo != NULL) //Andar o ponteiro na fila
        {
            pontAux = pontAux->proximo;
        }
        pontAux->proximo = novo; //B
    }

    pontFila->tamanho++; // C mesmo passo para todas opções 
}


int desinfileirarI(FilaI *pontFila)
{
    //VAZIA
    if (pontFila->inicio == NULL)
    {
        printf("Fila Vazia! ");
        return 0;
    }

    // 1 ou + DE 1 ELEMENTO
    else
    {
        NoSLI *pontAux = pontFila->inicio; //guarda o endereço do primeiro nó

        pontFila->inicio = pontAux->proximo; //faz o inicio da fila apontar para o segundo nó

        free(pontAux); //remove o antigo primeiro nó da memória

        pontFila->tamanho--; //diminuindo o tamanho da fila

        return 1;
    }
}

int proximoI(FilaI *pontFila)
{
    // VAZIA
    if (pontFila->inicio == NULL)
    {
        printf("Fila Vazia! ");
        return 0;
    }

    // 1 OU + DE 1 ELEMENTO
    else
    {
        return pontFila->inicio->valor;
    }
}