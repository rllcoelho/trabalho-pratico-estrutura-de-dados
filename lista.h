typedef struct tipoDeConta {
	int chave;//tipos: 1=conta corrente, 2=poupança, 3=investimento
	char descricao[30];
	float saldo;
}TipoDeConta;

typedef struct noLista {
	TipoDeConta *conteudo;
	struct noLista *prox;
}NoLista;

typedef struct listaSimples {
	NoLista *prim,*ult;
}ListaSimples;

ListaSimples* criaLista() {
	ListaSimples *lista;
	lista = (ListaSimples*) malloc (sizeof(ListaSimples));
	NoLista *cc,*poupanca,*invest;
	cc = (NoLista*) malloc (sizeof(NoLista));
	poupanca = (NoLista*) malloc (sizeof(NoLista));
	invest = (NoLista*) malloc (sizeof(NoLista));
	cc->conteudo->chave = 1;
	strcpy(cc->conteudo->descricao, "conta corrente");
	cc->conteudo->saldo = 0;
	cc->prox = poupanca;
	lista->prim = cc;
	poupanca->conteudo->chave = 2;
	strcpy(poupanca->conteudo->descricao, "poupanca");
	poupanca->conteudo->saldo = 0;
	poupanca->prox = invest;
	invest->conteudo->chave = 3;
	strcpy(invest->conteudo->descricao, "investimento");
	invest->conteudo->saldo = 0;
	invest->prox = NULL;
	lista->ult = invest;
	return lista;
}

NoLista* buscaTipoConta(ListaSimples* lista, char descricao[30]) {
	//Procura se há um tipo de conta com esse nome, retorna o tipo se encontrar ou NULL se não encontrar
	NoLista *aux;
	aux = lista->prim;
	while(aux){
		if (aux->conteudo->descricao == descricao) {
			return aux;
		}
		aux = aux->prox;
	}
	return NULL;
}

void inserirNoLista(ListaSimples** lista, NoLista* no) {
	(*lista)->ult->prox = no;
	(*lista)->ult = no;
	(*lista)->ult->prox = NULL;
	printf("Tipo de conta adicionado com sucesso\n\n\n");
}

void novoTipoConta(ListaSimples** lista, char descricao[30]) {
	if (buscaTipoConta(*lista, descricao)) {
		printf("Essa conta já possui esse tipo.\n\n\n");
		return;
	}
	NoLista *no;
	no = (NoLista*) malloc (sizeof(NoLista));
	no->conteudo->chave = (*lista)->ult->conteudo->chave+1;
	strcpy(no->conteudo->descricao, descricao);
	no->conteudo->saldo = 0;
	inserirNoLista(lista, no);
}

void movimentaSaldo(TipoDeConta** tipoConta, float valor, int acao){//ação 1 = creditar, ação 2 = debitar
	if (acao == 1)
		(*tipoConta)->saldo += valor;
	else
		(*tipoConta)->saldo -= valor;
	printf("Operação realizada com sucesso. Saldo atual: %.2f\n", (*tipoConta)->saldo);
}

void listaTiposConta() {

}