#include "pilhaI.h"


PilhaI *criarPilhaInt()
{
    PilhaI *nova = (PilhaI *) malloc(sizeof(PilhaI));
    nova->tamanho = 0;
    nova->topo = NULL;
    return nova;
}


void limparPilhaI(PilhaI *pontPilha)
{
    //VAZIA
    if (pontPilha->tamanho == 0)
    {
        printf("Lista Vazia!");
    }

    //1 ou + DE 1 ELEMENTO
    else
    {   
        NoSLI *pontAux = pontPilha->topo; //guarda o endereço do primeiro nó

        NoSLI *pontAux2 = pontAux->proximo; //guarda o endereço do próximo nó

        while (pontAux2 != NULL)
        {
            free(pontAux); //limpou o primeiro nó
            pontAux = pontAux2; //fez o primeiro apontar para o proximo
            pontAux2 = pontAux2->proximo; //fez o próximo apontar para o outro próximo
        }
        free(pontAux); //limpou o último que ficou

        pontPilha->tamanho = 0; //diminuiu o tamanho pra 0
        pontPilha->topo = NULL;
    }
}


void destruirPilhaI(PilhaI **pontpontPilha)
{
    limparPilhaI(*pontpontPilha);
    free(*pontpontPilha);
    *pontpontPilha = NULL;
}


void mostrarPilhaI(PilhaI *pontPilha)
{
    printf("Tamanho da Pilha = %d\n", pontPilha->tamanho); // SEMPRE MOSTRAR O TAMANHO
    
    //VAZIA

    if (pontPilha->tamanho == 0)
    {
        printf("Pilha Vazia\n");
    }

    // 1 OU + ELEMENTOS
    
    else
    {
        NoSLI *pontAux = pontPilha->topo;
        while (pontAux != NULL)
        {
            printf("%d -> ", pontAux->valor);
            pontAux = pontAux->proximo;
        }
        printf("NULL\n");
    }
}

void empilharPilhaI(int valor, PilhaI *pontPilha)
{
    NoSLI * novo;

    if (pontPilha->tamanho == 0)  // VAZIA
    {
        novo = criarNoSLI(valor, NULL);
    }

    else  // 1 OU + DE 1 ELEMENTO
    {
        novo = criarNoSLI(valor, pontPilha->topo);
    }

    pontPilha->topo = novo;
    
    pontPilha->tamanho++;

}


int desempilharPilhaI(PilhaI *pontPilha)
{
//VAZIA
    if (pontPilha->topo == NULL)
    {
        printf("Pilha Vazia! ");
        return 0;
    }

    // 1 ou + DE 1 ELEMENTO
    else
    {
        NoSLI *pontAux = pontPilha->topo; //guarda o endereço do primeiro nó

        pontPilha->topo = pontAux->proximo; //faz o inicio da lista apontar para o segundo nó

        free(pontAux); //remove o antigo primeiro nó da memória

        pontPilha->tamanho--; //diminuindo o tamanho da pilha

        return 1;
    }
}


int obterTopoPilhaI(PilhaI * pontPilha)
{
    // VAZIA
    if (pontPilha->topo == NULL)
    {
        printf("Pilha Vazia! ");
        return 0;
    }

    // 1 OU + DE 1 ELEMENTO
    else
    {
        return pontPilha->topo->valor;
    }
}