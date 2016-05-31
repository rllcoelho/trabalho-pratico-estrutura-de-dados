typedef struct noListaDupla {
    int numConta;
    listaSimples *tiposDeConta;
    struct noListaDupla *prox, *ant;
} NoListaDupla;

typedef struct listaDupla {
    NoListaDupla *prim, *ult;
    int tam;
}ListaDupla;

void criaListaDupla(ListaDupla **lista) {
    (*lista)->prim = NULL;
    (*lista)->ult = NULL;
    (*lista)->tam = 0;
}

void insereListaDupla(ListaDupla **lista, int conta) {
    NoListaDupla *novo;
    novo = (NoListaDupla*) malloc(sizeof(NoListaDupla));
    novo->numConta = conta;
    //se lista estiver vazia
    if ((*lista)->prim == NULL) {
        novo->ant = (*lista)->prim;
        novo->prox = (*lista)->ult;   
        (*lista)->ult = novo;  
    } else { //se lista não esver vazia, insere no inicio
        novo->ant = NULL;   
        novo->prox = (*lista)->prim;   
        (*lista)->prim->ant = novo; 
    }
    (*lista)->prim = novo;
    (*lista)->tam++;
}

int posicaoNoListaDupla(ListaDupla *lista, int conta) {
    int pos = 0;
    NoListaDupla *aux;
    aux = lista->prim;

    while(aux->prox != lista->ult) {
        if (aux->numConta == conta) {
            return pos;
        }
        aux = aux->prox;
        pos++;
    }
    return -1;
}

void removeNoListaDupla(ListaDupla **lista, int pos) {
    int i;
    NoListaDupla *removeNo, *seletor;

    if(pos == 1) { /* remoção do 1° elemento */
        removeNo = (*lista)->prim;
        (*lista)->prim = (*lista)->prim->prox;
        if((*lista)->prim == NULL)
            (*lista)->ult = NULL;
        else
            (*lista)->prim->ant = NULL;
    } else if(pos == (*lista)->tam) { /* remoção do último elemento */   
        removeNo = (*lista)->ult;
        (*lista)->ult->ant->prox = NULL;
        (*lista)->ult = (*lista)->ult->ant;
    } else { /* remoção em outro lugar */   
        seletor = (*lista)->prim;

        for(i = 1; i < pos; i++) {
            seletor = seletor->prox;
        }

        removeNo = seletor;
        seletor->ant->prox = seletor->prox;   
        seletor->prox->ant = seletor->ant;
    }

    free(removeNo->tiposDeConta);
    free(removeNo);
    (*lista)->tam--;   
}

NoListaDupla* exibeConta(ListaDupla *lista, int conta, int acao) {
    NoListaDupla *seletor;
    seletor = lista->prim;

    while(seletor){
        if (seletor->numConta == conta && acao == 1) {
            noLista *aux;
            aux = seletor->tiposDeConta->prim;
            printf("Essa conta possui os seguintes tipos, com seus respectivos saldos:\n");
            while(aux){
                printf("%s: %.2f\n", aux->conteudo->descricao, aux->conteudo->saldo);
            }
            printf("\n");
            return NULL;
        }
        if (seletor->numConta == conta && acao == 2) {
            return seletor;
        }
        seletor = seletor->prox;
    }
}
