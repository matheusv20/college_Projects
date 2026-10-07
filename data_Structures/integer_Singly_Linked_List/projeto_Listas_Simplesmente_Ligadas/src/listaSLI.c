#include "listaSLI.h"


ListaSLI * criarListaSLI()
{
    ListaSLI *nova = (ListaSLI *) malloc(sizeof(ListaSLI));
    nova->tamanho = 0;
    nova->inicio = NULL;
    return nova;
}



void mostrarListaSLI(ListaSLI *pontLista)
{
    printf("Tamanho da Lista = %d\n", pontLista->tamanho); // SEMPRE MOSTRAR O TAMANHO
    
    //VAZIA

    if (pontLista->tamanho == 0)
    {
        printf("Lista Vazia\n");
    }

    // 1 OU + ELEMENTOS
    
    else
    {
        NoSLI *pontAux = pontLista->inicio;
        while (pontAux != NULL)
        {
            printf("%d -> ", pontAux->valor);
            pontAux = pontAux->proximo;
        }
        printf("NULL\n");
    }
}



void inserirFimSLI(int valor, ListaSLI *pontLista)
{
    NoSLI *novo = criarNoSLI(valor, NULL); // A mesmo passo para todas as opções

    // VAZIA
    if (pontLista->inicio == NULL) // serve os dois: (lista->tamanho == 0) ou (lista->inicio == NULL)
    {
        pontLista->inicio = novo; //B
    }

    // 1 ou + DE 1 ELEMENTO
    else
    {
        NoSLI *pontAux = pontLista->inicio;
        while (pontAux->proximo != NULL) //Andar o ponteiro na lista
        {
            pontAux = pontAux->proximo;
        }
        pontAux->proximo = novo; //B
    }

    pontLista->tamanho++; // C mesmo passo para todas opções 

}



void InserirInicioSLI(int valor, ListaSLI *pontLista)
{
    NoSLI *novo = criarNoSLI(valor, NULL); // A mesmo passo para todas as opções

    // VAZIA
    if (pontLista->inicio == NULL) // serve os dois: (lista->tamanho == 0) ou (lista->inicio == NULL)
    {
        pontLista->inicio = novo; //B
    }

    // 1 ou + DE 1 ELEMENTO

    else
    {   
        novo->proximo = pontLista->inicio;
        pontLista->inicio = novo; //B
    }

    pontLista->tamanho++; //C mesmo passo para todas opções 

}


int inserirPosicaoLSLI(int valor, int posicao, ListaSLI *pontLista)
{
    if (posicao < 0)
    {
        printf("Não existe posição negativa!\n");
        return 0;
    }
    else if (pontLista->tamanho == 0)
    {
        printf("Não é posível inserir elementos em uma lista vazia!\n");
        return 0;
    }

    else if (posicao >= pontLista->tamanho)
    {
        printf("Não é possível inserir elementos em uma posição maior que o tamanho da lista!\n");
        return 0;
    }
    else
    {
        NoSLI *novo = criarNoSLI(valor, NULL);

        //1 ELEMENTO
        if (pontLista->tamanho == 1)
        {
            InserirInicioSLI(valor, pontLista);
            return 1;
        }

        // + DE 1 ELEMENTO
        else
        {
            if (posicao == 0)
            {
                InserirInicioSLI(valor, pontLista);
                return 1;
            }
            
            else
            {
                NoSLI *pontAux = pontLista->inicio;
                            
                int contador = 0;

                while (contador != (posicao - 1))
                    {
                        pontAux = pontAux->proximo;
                        contador++;
                    }
                            
                novo->proximo = pontAux->proximo;

                pontAux->proximo = novo;

                novo->valor = valor;

                pontLista->tamanho++;
            }
            return 1;
        }
    }
}



int obterValorInicioSLI(ListaSLI *pontLista)
{
    // VAZIA
    if (pontLista->inicio == NULL)
    {
        printf("Lista Vazia! ");
        return 0;
    }

    // 1 OU + DE 1 ELEMENTO
    else
    {
        return pontLista->inicio->valor;
    }


}


int obterValorFimSLI(ListaSLI *pontLista)
{
    //VAZIA
    if (pontLista->inicio == NULL)
    {
        printf("Lista Vazia! ");
        return 0;
    }

    // 1 OU + DE 1 ELEMENTO
    else
    {
        NoSLI *pontAux = pontLista->inicio;
        while (pontAux->proximo != NULL)
        {
            pontAux = pontAux->proximo;
        }
        return pontAux->valor;
    }
}

int obterValorPosicaoSLI(int posicao, ListaSLI *pontLista)
{
    if (posicao < 0)
    {
        printf("Não existe posição negativa!\n");
        return 0;
    }
    else if (pontLista->tamanho == 0)
    {
        printf("Não é posível obter o valor de elementos em uma lista vazia!\n");
        return 0;
    }

    else if (posicao >= pontLista->tamanho)
    {
        printf("Não é possível obter o valor de elementos em uma posição maior que o tamanho da lista!\n");
        return 0;
    }
    else 
    {   
        // 1 ELEMENTO
        if (pontLista->tamanho == 1)
        {
            return pontLista->inicio->valor;
        }
        
        else
        {
            NoSLI *pontAux = pontLista->inicio;

            int contador = 0;

            while(contador < posicao)
            {
                pontAux = pontAux->proximo;
                contador++;
            }

            return pontAux->valor;
        }
    }
}


// 0 -  NÃO REMOVEU
// 1 - REMOVEU
int removerInicioLSLI(ListaSLI *pontLista)
{
    //VAZIA
    if (pontLista->inicio == NULL)
    {
        printf("Lista Vazia! ");
        return 0;
    }

    // 1 ou + DE 1 ELEMENTO
    else
    {
        NoSLI *pontAux = pontLista->inicio; //guarda o endereço do primeiro nó

        pontLista->inicio = pontAux->proximo; //faz o inicio da lista apontar para o segundo nó

        free(pontAux); //remove o antigo primeiro nó da memória

        pontLista->tamanho--; //diminuindo o tamanho da lista

        return 1;
    }
}

// 0 -  NÃO REMOVEU
// 1 - REMOVEU
int removerFimLSLI(ListaSLI *pontLista)
{
    //VAZIA
    if (pontLista->inicio == NULL)
    {
        printf("Lista Vazia! ");
        return 0;
    }

    // 1 ou + DE 1 ELEMENTO
    else
    {
        NoSLI *pontAux = pontLista->inicio;
        while (pontAux->proximo->proximo != NULL)
        {
            pontAux = pontAux->proximo;
        }
        free(pontAux->proximo);
        pontAux->proximo = NULL;
        pontLista->tamanho--;
        return 1;
    }
}


int removerPosicaoLSLI(int posicao, ListaSLI *pontLista)
{
    if (posicao < 0)
    {
        printf("Não existe posição negativa!\n");
        return 0;
    }
    else if (pontLista->tamanho == 0)
    {
        printf("Não é posível remover elementos em uma lista vazia!\n");
        return 0;
    }

    else if (posicao >= pontLista->tamanho)
    {
        printf("Não é possível remover elementos em uma posição maior que o tamanho da lista!\n");
        return 0;
    }
    else
    {   
        // 1 ELEMEMENTO
        if (pontLista->tamanho == 1)
        {
            removerInicioLSLI(pontLista);
            return 1;
        }
        
        // + DE 1 ELEMENTOS QUERENDO REMOVER O PRIMEIRO
        else if (posicao == 0)
        {
            removerInicioLSLI(pontLista);
            return 1;
        }
        
        // + DE 1 ELEMENTOS QUERENDO REMOVER O ÚLTIMO
        else if (posicao == ((pontLista->tamanho) - 1))
        {
            removerFimLSLI(pontLista);
            return 1;
        }

        // + DE 1 ELEMENTO QUERENDO REMOVER QUALQUER 1
        else
        {
            NoSLI *pontAux = pontLista->inicio;
            NoSLI *pontAux2 = pontLista->inicio;
                            
            int contador = 0;

            while (contador != (posicao - 1))
                {
                    pontAux = pontAux->proximo;
                    contador++;
                }
            
            pontAux2 = pontAux->proximo;
            pontAux->proximo = pontAux2->proximo;

            free(pontAux2);
            pontLista->tamanho--;
            return 1;
        }
    }
}


void limparLSLI(ListaSLI *pontLista)
{
    //VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("Lista Vazia!");
    }

    //1 ou + DE 1 ELEMENTO
    else
    {   
        NoSLI *pontAux = pontLista->inicio; //guarda o endereço do primeiro nó

        NoSLI *pontAux2 = pontAux->proximo; //guarda o endereço do próximo nó

        while (pontAux2 != NULL)
        {
            free(pontAux); //limpou o primeiro nó
            pontAux = pontAux2; //fez o primeiro apontar para o proximo
            pontAux2 = pontAux2->proximo; //fez o próximo apontar para o outro próximo
        }
        free(pontAux); //limpou o último que ficou

        pontLista->tamanho = 0; //diminuiu o tamanho pra 0
        pontLista->inicio = NULL;
    }
}


void destruirLSLI(ListaSLI **pontPontLista)
{
    limparLSLI(*pontPontLista);
    free(*pontPontLista);
    *pontPontLista = NULL;
}

int trocarValorInicioLSLI(int valor, ListaSLI *pontLista)
{
    //VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("Impossível Trocar o Valor de uma Lista Vazia!");
        return 0;
    }
    // 1 ou + DE 1 ELEMENTO
    else
    {
        pontLista->inicio->valor = valor;
        return 1;
    }
}

int trocarValorFimLSLI(int valor, ListaSLI *pontLista)
{
    //VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("Impossível Trocar o Valor de uma Lista Vazia!");
        return 0;
    }
    // 1 ou + DE 1 ELEMENTO
    else
    {
        NoSLI *pontAux = pontLista->inicio; //guarda o endereço do primeiro nó

        while (pontAux->proximo != NULL)
        {
            pontAux = pontAux->proximo;
        }

        pontAux->valor = valor;

        return 1;
    }
}

int trocarPosicaoLSLI(int valor, int posicao, ListaSLI *pontLista)
{
    if (posicao < 0)
    {
        printf("Não existe posição negativa!\n");
        return 0;
    }
    else if (pontLista->tamanho == 0)
    {
        printf("Não é posível trocar elementos em uma lista vazia!\n");
        return 0;
    }

    else if (posicao >= pontLista->tamanho)
    {
        printf("Não é possível trocar o elemento em uma posição maior que o tamanho da lista!\n");
        return 0;
    }
    else 
    {   
        // 1 ELEMENTO
        if (pontLista->tamanho == 1)
        {
            pontLista->inicio->valor = valor;
            return 1;
        }
        
        else
        {
            NoSLI *pontAux = pontLista->inicio;

            int contador = 0;

            while(contador < posicao)
            {
                pontAux = pontAux->proximo;
                contador++;
            }

            pontAux->valor = valor;
            return 1;
        }
    }
}


