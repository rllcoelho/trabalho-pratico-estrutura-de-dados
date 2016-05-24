typedef struct cliente {
    int cpf;
    char nome[30], telefone[16], rg[10];
} Cliente;

typedef struct noArvore {
    Cliente *conteudo;
    //ListaDupla *contas;
    int *contas;
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
	printf("entrou\n");
	if(!arvore || !arvore->conteudo){
		arvore = (NoArvore*) malloc (sizeof(NoArvore));
		arvore->conteudo = c;
		printf("%d\n",arvore->conteudo->cpf);
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

void novoCliente(NoArvore* arvore, int cpf, char nome[30], char tel[16], char rg[10]){
	Cliente *c;
	c = (Cliente*) malloc (sizeof(Cliente));
	c->cpf = cpf;
	strcpy(c->nome, nome);
	strcpy(c->telefone, tel);
	strcpy(c->rg, rg);
	inserirNoArvore(arvore, c);
	printf("%d\n",arvore->conteudo->cpf);
}

Cliente* encontrarPorCPF(NoArvore* arvore, int cpf){
	printf("aaaaaaa\n");
	if(!arvore){
		return 0;
	}
	if(arvore->conteudo->cpf < cpf){
		printf("%d\n",arvore->conteudo->cpf);
		encontrarPorCPF(arvore->direita, cpf);
		return 0;
	}
	if(arvore->conteudo->cpf > cpf)
		encontrarPorCPF(arvore->esquerda, cpf);
	else
		return arvore->conteudo;
	printf("aaaaaaa\n");
	return 0;
}

void exibirCliente(NoArvore arvore, int cpf){
	Cliente *c;
	c = encontrarPorCPF(&arvore, cpf);
	printf("%d\n",arvore.conteudo->cpf);
	if (c){
		printf("Dados do cliente:\n\n");
		printf("Nome: %s\n", c->nome);
		printf("Telefone: %s\n", c->telefone);
		printf("RG: %s\n", c->rg);
	}else
		printf("Não há cliente com esse CPF no sistema.\n");	
}

void alterarDadosCliente(NoArvore arvore, int cpf, char nome[30], char tel[16], char rg[10]){
	Cliente *c;
	c = encontrarPorCPF(&arvore, cpf);
	strcpy(c->nome, nome);
	strcpy(c->telefone, tel);
	strcpy(c->rg, rg);
	printf("Cliente editado com sucesso!");
}

void antecessor(NoArvore arvore, NoArvore *no){
	if(no->direita){
        antecessor(arvore, no->direita);
        return;
    }
    arvore.conteudo = no->conteudo;
    arvore.contas = no->contas;
    arvore = *no;
    no = no->esquerda;
    free(&arvore);
}

void excluirNoArvore(NoArvore *arvore, Cliente* c){
	NoArvore* aux;
	if(!arvore){
		printf("Não há cliente com esse cpf no sistema.");
		return;
	}
	if(c->cpf < arvore->conteudo->cpf){
        excluirNoArvore(arvore->esquerda, c);
        return;
	}
    if(c->cpf > arvore->conteudo->cpf){
        excluirNoArvore(arvore->direita, c);
        return;
	}
    if(arvore->direita == NULL){
        aux = arvore;
        arvore = arvore->esquerda;
        //excluirListaDupla(aux->contas); //mudar nome para função do arquivo de listas duplas
        free(aux->conteudo);
        free(aux);
        return;
    }
    if(arvore->esquerda){
        antecessor(*arvore,arvore->esquerda);
        return;
    }
    aux = arvore;
    arvore = arvore->direita;
    //excluirListaDupla(aux->contas); //mudar nome para função do arquivo de listas duplas
    free(aux->conteudo);
    free(aux);
}
