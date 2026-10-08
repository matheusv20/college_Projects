#include "listaDLI.h"

ListaDLI *criarListaDLI()
{
    ListaDLI *nova = (ListaDLI *) malloc(sizeof(ListaDLI));
    nova->inicio = NULL;
    nova->fim = NULL;
    nova->tamanho = 0;
    return nova;
}

//ordem para inserir elementos:
//primeiro preocupa com o proximo e o anterior do novo nó
//depois preocupa com o inicio e fim da lista
//por fim altera a localização do início ou fim da lista

void inserirInicioLDLI(int valor, ListaDLI *pontLista)
{   
    NoDLI *novo = criarNoDLI(valor, NULL, NULL); //criando o novo nó

    //LISTA VAZIA
    if (pontLista->tamanho == 0)
    {
        novo->proximo = NULL;
        novo->anterior = NULL;
        pontLista->inicio = novo;
        pontLista->fim = novo;
    }

    //LISTA COM 1 ELEMENTO
    else if (pontLista->tamanho == 1)
    {
        novo->proximo = pontLista->fim; //O próximo do novo nó aponta para o fim da lista
        novo->anterior = NULL; //o anterior do novo nó é NULL (primeiro elemento)
        pontLista->fim->anterior = novo; //O anterior do fim da lista é o próprio novo nó
        pontLista->inicio = novo; //o início da lista é o próprio novo nó
    }

    //LISTA COM + DE 1 ELEMENTO
    else
    {
        novo->anterior = NULL; //não tem elemento antes
        novo->proximo = pontLista->inicio; //o próximo elemento é o primeiro da lista
        pontLista->inicio->anterior = novo; //o anterior ao primeiro elemento da lista é o novo nó
        pontLista->inicio = novo; //o novo nó passa a ser o primeiro elemento da lista
    }
    pontLista->tamanho++;
}

void inserirFimLDLI(int valor, ListaDLI *pontLista)
{   
    NoDLI *novo = criarNoDLI(valor, NULL, NULL); //criando o novo nó

    //LISTA VAZIA
    if (pontLista->tamanho == 0)
    {
        novo->proximo = NULL;
        novo->anterior = NULL;
        pontLista->inicio = novo;
        pontLista->fim = novo;
    }

    //LISTA COM 1 ELEMENTO
    else if (pontLista->tamanho == 1)
    {
        novo->anterior = pontLista->inicio; //O nó anterior do novo nó é o começo da lista
        novo->proximo = NULL; //o proximo do novo nó é nulo
        pontLista->inicio->proximo = novo; //O próximo nó do início da lista é o novo
        pontLista->fim = novo; //o fim da lista é o próprio novo nó
    }

    //LISTA COM + DE 1 ELEMENTO
    else
    {
        novo->proximo = NULL; //não tem elementos após o último
        novo->anterior = pontLista->fim; //o elemento alterior ao novo nó é o último da lista
        pontLista->fim->proximo = novo; //o próximo elemento do fim da lista é o novo
        pontLista->fim = novo; //o novo nó passa a ser o fim da lista
    }
    pontLista->tamanho++;
}

void inserirElementoPosicaoLDLI(int valor, int posicao, ListaDLI *pontLista)
{
    //LISTA VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("A lista está vazia, logo não é possível inserir elementos em nenhuma posição!");
    }

    //POSIÇÃO NEGATIVA
    else if (posicao < 0)
    {
        printf("A posição enviada é negativa, logo não é possível inserir o elemento!");
    }

    //POSIÇÃO MAIOR QUE O TAMANHO - 1
    else if (posicao > (pontLista->tamanho - 1))
    {
        printf("A posição enviada é maior que o tamanho da lista, logo não é possível inserir o elemento!");
    }

    //POSIÇÃO 0
    else if (posicao == 0)
    {   
        inserirInicioLDLI(valor, pontLista);
    }

    else
    {   
        NoDLI *novo = criarNoDLI(valor, NULL, NULL);
        NoDLI *pontAux = pontLista->inicio;
        int contador = 0;

        while(contador < posicao)
        {
            pontAux = pontAux->proximo;
            contador++;
        }

        novo->proximo = pontAux;
        novo->anterior = pontAux->anterior;

        pontAux->anterior->proximo = novo;
        pontAux->anterior = novo;

        pontLista->tamanho++;

    }
}



void limparLDLI(ListaDLI *pontLista)
{   
    //LISTA VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("Um total de %d elemento(s) da lista foi(ram) limpado(s) com sucesso!", pontLista->tamanho);
    }
    
    //LISTA COM 1 ELEMENTO
    else if (pontLista->tamanho == 1)
    {
        free(pontLista->inicio); //freela o primeiro elemento

        pontLista->inicio = NULL; //o início vai apontar pro nada
        pontLista->fim = NULL; //o fim vai apontar pro nada
        

        printf("Um total de %d elemento(s) da lista foi(ram) limpado(s) com sucesso!", pontLista->tamanho);
    }

    //LISTA COM + DE 1 ELEMENTO
    else
    {
        NoDLI *pontAux = pontLista->inicio; //guarda o endereço do primeiro nó

        while(pontAux != pontLista->fim) //ou while(pontAux->proximo != pontLista->fim)
        {   
            pontAux = pontAux->proximo; //vai avançando o pont aux
            free(pontAux->anterior); //vai freelando todos elemento até chegar no último
        }
        free(pontAux); //chegou no último, saiu do nó e freelou o que faltava

        pontLista->inicio = NULL; //o início vai apontar pro nada
        pontLista->fim = NULL; //o fim vai apontar pro nada
    }

    pontLista->tamanho = 0;
}

void destruirLDLI(ListaDLI **pontLista)
{
    limparLDLI(*pontLista);

    free(*pontLista);

    *pontLista = NULL;


}



//ordem para remover elementos:
//transforma o inicio/fim antigo em um trabalho com próximo/anterior
//freela o antigo último/primeiro nó
//por fim altera a localização do início ou fim da lista

int removerInicioLDLI(ListaDLI *pontLista)
{   
    //return 1 = deu certo
    //return 0 = deu errado

    //LISTA VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("A lista está vazia, logo não é possível remover o primeiro elemento!");
        return 0;
    }

    //1 ELEMENTO
    else if (pontLista->tamanho == 1)
    {
        free(pontLista->inicio); //freela o inicio

        pontLista->inicio = NULL; //faz o inicio apontar para null
        pontLista->fim = NULL; //faz o fim apontar para null

        pontLista->tamanho--;

        return 1;
    }

    //MAIS DE 1 ELEMENTO
    else
    {
        pontLista->inicio = pontLista->inicio->proximo; //faz o inicio apontar para o novo inicio

        free(pontLista->inicio->anterior); // apagando o primeiro nó
        
        pontLista->inicio->anterior = NULL; //o primeiro nó antigo passa a ser nulo

        pontLista->tamanho--;

        return 1;
    }
}

int removerFimLDLI(ListaDLI *pontLista)
{
    //return 1 = deu certo
    //return 0 = deu errado

    //LISTA VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("A lista está vazia, logo não é possível remover o último elemento!");
        return 0;
    }

    //1 ELEMENTO
    else if (pontLista->tamanho == 1)
    {
        free(pontLista->fim); //freela o fim

        pontLista->fim = NULL; //faz o fim apontar para null
        pontLista->inicio = NULL; //faz o inicio apontar para null

        pontLista->tamanho--;

        return 1;
    }

    //MAIS DE 1 ELEMENTO
    else
    {
        pontLista->fim = pontLista->fim->anterior; //faz o fim apontar para o novo fim

        free(pontLista->fim->proximo); //apagando o último nó
        
        pontLista->fim->proximo = NULL; //o próximo do novo fim passa a ser

        pontLista->tamanho--;

        return 1;
    }
}

int removerElementoPosicaoLDLI(int posicao, ListaDLI *pontLista)
{
    //LISTA VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("A lista está vazia, logo não é possível remover elementos em nenhuma posição!");
    }

    //POSIÇÃO NEGATIVA
    else if (posicao < 0)
    {
        printf("A posição enviada é negativa, logo não é possível remover o elemento!");
    }

    //POSIÇÃO MAIOR QUE O TAMANHO - 1
    else if (posicao > (pontLista->tamanho - 1))
    {
        printf("A posição enviada é maior que o tamanho da lista, logo não é possível inserir o elemento!");
    }

    //POSIÇÃO 0
    else if (posicao == 0)
    {   
        removerInicioLDLI(pontLista);
    }

    else if (posicao == pontLista->tamanho - 1)
    {   
        removerFimLDLI(pontLista);
    }

    else
    {   
        
        NoDLI *pontAux = pontLista->inicio;
        int contador = 0;

        while(contador < posicao)
        {
            pontAux = pontAux->proximo;
            contador++;
        }

        pontAux->anterior->proximo = pontAux->proximo;
        pontAux->proximo->anterior = pontAux->anterior;

        free(pontAux);

        pontLista->tamanho--;

    }
}



int obterValorInicioLDLI(ListaDLI *pontLista)
{
    //LISTA VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("A lista está vazia, logo não é possível obter o primeiro elemento!");
        return 0;
    }

    //1 ELEMENTO
    else if (pontLista->tamanho == 1)
    {
        return pontLista->inicio->valor;
    }

    //MAIS DE 1 ELEMENTO
    else
    {
        return pontLista->inicio->valor;
    }
}

int obterValorFimLDLI(ListaDLI *pontLista)
{
    //LISTA VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("A lista está vazia, logo não é possível obter o primeiro último!");
        return 0;
    }

    //1 ELEMENTO
    else if (pontLista->tamanho == 1)
    {
        return pontLista->fim->valor;
    }

    //MAIS DE 1 ELEMENTO
    else
    {
        return pontLista->fim->valor;
    }
}

int obterValorPosicaoLDLI(int posicao, ListaDLI *pontLista)
{
    //LISTA VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("A lista está vazia, logo não é possível obter o valor de nenhuma posição!");
        return 0;
    }

    //POSIÇÃO NEGATIVA
    else if (posicao < 0)
    {
        printf("A posição enviada é negativa, logo não é possível obter o valor!");
        return 0;
    }

    //POSIÇÃO MAIOR QUE O TAMANHO - 1
    else if (posicao > (pontLista->tamanho - 1))
    {
        printf("A posição enviada é maior que o tamanho da lista, logo não é possível obter o valor!");
        return 0;
    }

    //1 ELEMENTO
    else if (pontLista->tamanho == 1)
    {   
        return pontLista->inicio->valor;
    }

    //MAIS DE 1 ELEMENTO
    else
    {   
        NoDLI *pontAux = pontLista->inicio;
        int contador = 0;

        while(contador != posicao)
        {
            pontAux = pontAux->proximo;
            contador++;
        }

        return pontAux->valor;
    }
}



int trocarValorInicioLDLI(int valor, ListaDLI *pontLista)
{
    //LISTA VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("A lista está vazia, logo não é possível trocar o valor do primeiro elemento!");
        return 0;
    }

    //1 ELEMENTO
    else if (pontLista->tamanho == 1)
    {   
        pontLista->inicio->valor = valor;
        return 1;
    }

    //MAIS DE 1 ELEMENTO
    else
    {
        pontLista->inicio->valor = valor;
        return 1;
    }
}

int trocarValorFimLDLI(int valor, ListaDLI *pontLista)
{
    if (pontLista->tamanho == 0)
    {
        printf("A lista está vazia, logo não é possível trocar o valor do último elemento!");
        return 0;
    }

    //1 ELEMENTO
    else if (pontLista->tamanho == 1)
    {   
        pontLista->inicio->valor = valor;
        return 1;
    }

    //MAIS DE 1 ELEMENTO
    else
    {
        pontLista->inicio->valor = valor;
        return 1;
    }
}

int trocarValorPosicaoLDLI(int valor, int posicao, ListaDLI *pontLista)
{
    //LISTA VAZIA
    if (pontLista->tamanho == 0)
    {
        printf("A lista está vazia, logo não é possível trocar o valor de nenhuma posição!");
        return 0;
    }

    //POSIÇÃO NEGATIVA
    else if (posicao < 0)
    {
        printf("A posição enviada é negativa, logo não é possível trocar o valor!");
        return 0;
    }

    //POSIÇÃO MAIOR QUE O TAMANHO - 1
    else if (posicao > (pontLista->tamanho - 1))
    {
        printf("A posição enviada é maior que o tamanho da lista, logo não é possível trocar o valor!");
        return 0;
    }

    //1 ELEMENTO
    else if (pontLista->tamanho == 1)
    {   
        pontLista->inicio->valor = valor;
        return 1;
    }

    //MAIS DE 1 ELEMENTO
    else
    {   
        NoDLI *pontAux = pontLista->inicio;
        int contador = 0;

        while(contador != posicao)
        {
            pontAux = pontAux->proximo;
            contador++;
        }

        pontAux->valor = valor;

        return 1;
    }
}



void mostrarListaDLI(ListaDLI *pontLista)
{
    
    printf("Tamanho: %d\n", pontLista->tamanho);

    if (pontLista->tamanho == 0)
    {
        printf("NULL\n\n");
    }
    
    else
    {
        NoDLI *pontAux = pontLista->inicio;

        printf("NULL <- ");
        
        while (pontAux != pontLista->fim)
        {
            
            printf("%d <-> ", pontAux->valor);
            pontAux = pontAux->proximo;
        }
       
        printf("%d -> NULL\n\n", pontAux->valor);
    }
}


int saoIdenticasLDLI(ListaDLI *pontLista, ListaDLI *pontLista2)
{   
    NoDLI *pontAux = pontLista->inicio;
    NoDLI *pontAux2 = pontLista2->inicio;


    if (pontLista->tamanho != pontLista2->tamanho)
    {
        return 0;
    }
    
    while ((pontAux != NULL) && (pontAux2 != NULL))
    {
        if (pontAux->valor != pontAux2->valor)
        {
            return 0;
        }
        
        pontAux = pontAux->proximo;
        pontAux2 = pontAux2->proximo;

    }   
    
    return 1;

}