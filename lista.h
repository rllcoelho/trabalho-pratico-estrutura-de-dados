typedef struct tipoDeConta {
	int chave;
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

ListaSimples* criaLista() {// Cria uma lista com os tipos de conta iniciais
	ListaSimples *lista;
	lista = (ListaSimples*) malloc (sizeof(ListaSimples));
	NoLista *cc,*poupanca,*invest;
	cc = (NoLista*) malloc (sizeof(NoLista));
	poupanca = (NoLista*) malloc (sizeof(NoLista));
	invest = (NoLista*) malloc (sizeof(NoLista));
	cc->conteudo = (TipoDeConta*) malloc (sizeof(TipoDeConta));
	cc->conteudo->chave = 1;
	strcpy(cc->conteudo->descricao, "conta corrente");
	cc->conteudo->saldo = 0;
	cc->prox = poupanca;
	lista->prim = cc;
	poupanca->conteudo = (TipoDeConta*) malloc (sizeof(TipoDeConta));
	poupanca->conteudo->chave = 2;
	strcpy(poupanca->conteudo->descricao, "poupanca");
	poupanca->conteudo->saldo = 0;
	poupanca->prox = invest;
	invest->conteudo = (TipoDeConta*) malloc (sizeof(TipoDeConta));
	invest->conteudo->chave = 3;
	strcpy(invest->conteudo->descricao, "investimento");
	invest->conteudo->saldo = 0;
	invest->prox = NULL;
	lista->ult = invest;
	return lista;
}

TipoDeConta* buscarTipoConta(ListaSimples* lista, char nome[30]) {
	//Procura se há um tipo de conta com esse nome, retorna o tipo se encontrar ou NULL se não encontrar
	NoLista *aux;
	aux = lista->prim;
	while(aux){
		if (!strcmp(aux->conteudo->descricao, nome)) {
			return aux->conteudo;
		}
		aux = aux->prox;
	}
	return NULL;
}

void novoTipoConta(ListaSimples** lista, char descricao[30]) {
	if (buscarTipoConta(*lista, descricao)) {
		printf("Essa conta já possui esse tipo.\n\n\n");
		return;
	}
	NoLista *no;
	no = (NoLista*) malloc (sizeof(NoLista));
	no->conteudo = (TipoDeConta*) malloc (sizeof(TipoDeConta));
	strcpy(no->conteudo->descricao, descricao);
	no->conteudo->saldo = 0;
	(*lista)->ult->prox = no;
	(*lista)->ult = no;
	(*lista)->ult->prox = NULL;
	printf("Tipo de conta adicionado com sucesso\n\n\n");
}

void movimentarSaldo(TipoDeConta** tipoConta, float valor, int acao){//ação 1 = creditar, ação 2 = debitar
	if (acao == 1)
		(*tipoConta)->saldo += valor;
	else if ((*tipoConta)->saldo >= valor)
		(*tipoConta)->saldo -= valor;
	else {
		printf("Operação falhou: Saldo insuficiente.\n\n\n");
		return;
	}
	printf("Operação realizada com sucesso. Saldo atual em %s: %.2f\n\n\n",(*tipoConta)->descricao, (*tipoConta)->saldo);
}

void editarTipoConta(TipoDeConta* tipoConta){
	if (tipoConta->chave == 1 || tipoConta->chave == 2 || tipoConta->chave == 3) {
		printf("Você não pode mudar o nome dos tipos de conta básicos.\n\n\n");
		return;
	} 
	printf("Digite o novo nome do tipo de conta: ");
	fgets(tipoConta->descricao, 30, stdin);
}

void exibirTipoConta(TipoDeConta* tipoConta){
	printf("Nome: %s\n", tipoConta->descricao);
	printf("Saldo: %.2f\n\n\n", tipoConta->saldo);
}

void listarTiposConta(ListaSimples* c) {
	NoLista *aux;
	aux = c->prim;
	while(aux){
		exibirTipoConta(aux->conteudo);
		aux = aux->prox;
	}
}

void TransferirSaldoTipoConta(TipoDeConta** tipoConta, TipoDeConta** tipoConta2, float valor){
	if ((*tipoConta)->saldo >= valor) {
		movimentarSaldo(tipoConta, valor, 2);
		movimentarSaldo(tipoConta2, valor, 1);
	} else {
		printf("Operação falhou: %s não possui saldo insuficiente.\n\n\n", (*tipoConta)->descricao);
		return;
	}
}

void removerNoLista(ListaSimples** lista, TipoDeConta** tipoConta) {
	if ((*tipoConta)->chave == 1 || (*tipoConta)->chave == 2 || (*tipoConta)->chave == 3) {
		printf("Você não pode mudar os tipos de conta básicos.\n\n\n");
		return;
	}
	NoLista *aux, *aux2;
	aux = (*lista)->prim;
	aux2 = aux->prox;
	while(aux && strcmp(aux->prox->conteudo->descricao, (*tipoConta)->descricao)) {
		aux = aux->prox;
		aux2 = aux2->prox;
	}
	if (aux2 == (*lista)->ult)
		(*lista)->ult = aux;
	aux->prox = aux2->prox;
	free(aux2->conteudo);
	free(aux2);
	printf("Tipo de conta removido com sucesso!\n\n\n");
}