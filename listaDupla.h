#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct noListaDupla
{
    int numConta;
    TipoDeConta *tiposDeConta;
    struct nolistaDupla *prox, *ant;
} NoListaDupla;

typedef struct listaDupla
{
    NoListaDupla *prim, *ult;
    int tam;
}ListaDupla;

void criaListaDupla(ListaDupla *lista)
{
    lista->prim = NULL;
    lista->ult = NULL;
    lista->tam = 0
}

void insereListaDupla(ListaDupla *lista, int conta)
{
    NoListaDupla *novo;
    if (novo = malloc(sizeof(NoListaDupla)))
    {
        novo->conta = conta;
        //se lista estiver vazia
        if (lista->prim == NULL)
        {
            novo->ant = lista->prim;
            novo->prox = lista->ult;   
            lista->ult = novo;  
        }
        //se lista não esver vazia, insere no inicio
        else {
            novo->ant = NULL;   
            novo->prox = lista->prim;   
            lista->prim->ant = novo; 
        }
        lista->prim = novo;   
    }
    lista->tamanho++;
}

int posicaoNoListaDupla(ListaDupla *lista, int conta)
{
    int pos = 0;
    NoListaDupla *aux;
    aux = lista->prim;

    while(aux->prox != lista->ult)
    {
        if (lista->conta == conta)
        {
            return pos;
        }
        aux = aux->prox;
        pos++;
    }
    return -1;
}

void removeNoListaDupla(ListaDupla *lista, int pos)
{
    int i;
    NoListaDupla *removeNo, *seletor;

    if(pos == 1)
    { /* remoção do 1° elemento */
        removeNo = lista->prim;
        lista->prim = lista->prim->prox;
        if(lista->prim == NULL)
            lista->fim = NULL;
        else
            lista->prim->ant == NULL;
    }
    else if(pos == lista->tam)
    { /* remoção do último elemento */   
        removeNo = lista->fim;
        lista->fim->ant->prox = NULL;
        lista->fim = lista->fim->ant;
    }
    else { /* remoção em outro lugar */   
        seletor = lista->prim;

        for( int i = 1; i < pos; i++)
        {
            seletor = seletor->prox;
        }

        removeNo = seletor;
        seletor->ant->prox = seletor->prox;   
        seletor->prox->ant = seletor->ant;
    }

    free(removeNo->tiposDeConta);
    free(removeNo);
    lista->tam--;   
}

void exibeNo(ListaDupla *lista, int pos)
{
    NoListaDupla *seletor;
    seletor = lista->prim;

    for (int i = 0; i < pos; ++i)
    {
        seletor = seletor-prox;
    }

    printf("Conta de número: %d\n", seletor->conta);
    //lista os tipos de conta associados a esta conta
}
