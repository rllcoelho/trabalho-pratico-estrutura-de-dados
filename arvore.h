typedef struct cliente {
    int cpf;
    char nome[30], telefone[16], rg[10];
} Cliente;

typedef struct noArvore {
    Cliente *conteudo;
    ListaDupla *contas;
    struct noArvore *esquerda, *direita;
} NoArvore;

NoArvore criaArvore(){
	NoArvore novaArvore;
	novaArvore.conteudo = NULL;
	novaArvore.contas = NULL;
	novaArvore.esquerda = NULL;
	novaArvore.direita = NULL;
	return novaArvore;
}

void inserirNoArvore(NoArvore* arvore, Cliente* c){
	if(arvore == NULL){
		arvore = (NoArvore*) malloc (sizeof(NoArvore));
		arvore->conteudo = c;
		arvore->contas = NULL;
		arvore->esquerda = NULL;
		arvore->direita = NULL;
		return;
	}
	if(arvore->conteudo->cpf < c->cpf){
		inserirNoArvore(arvore->direita, c);
		return;
	}
	if(arvore->conteudo->cpf > c->cpf)
		inserirNoArvore(arvore->esquerda, c);
	else
		printf("Já existe um cliente cadastrado com esse cpf.\n");
}

void excluirNoArvore(NoArvore* arvore, Cliente* c){

}

void novoCliente(NoArvore* arvore, int cpf, char nome[30], char tel[16], char rg[10]){
	Cliente *c;
	c = (Cliente*) malloc (sizeof(Cliente));
	c->cpf = cpf;
	strcpy(c->nome, nome);
	strcpy(c->telefone, tel);
	strcpy(c->rg, rg);
	inserirNoArvore(arvore, c);
}

Cliente encontrarPorCPF(NoArvore* arvore, int cpf){

}

void exibirCliente(Cliente c){

}

void alterarDadosCliente(int cpf, char nome[30], char tel[16]){

}
