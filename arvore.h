typedef struct cliente {
    int cpf;
    char nome[30], telefone[16], rg[10];
} Cliente;

typedef struct noArvore {
    Cliente *conteudo;
    ListaDupla *contas;
    struct noArvore *esquerda, *direita;
} NoArvore;

NoArvore* criaArvore(){
	NoArvore *novaArvore;
	novaArvore = (NoArvore*) malloc (sizeof(NoArvore));
	novaArvore->conteudo = NULL;
	novaArvore->contas = criaListaDupla();
	novaArvore->esquerda = NULL;
	novaArvore->direita = NULL;
	return novaArvore;
}

void inserirNoArvore(NoArvore** arvore, Cliente* c){
	if(!(*arvore) || !(*arvore)->conteudo){
		*arvore = criaArvore();
		(*arvore)->conteudo = c;
		printf("Cliente adicionado com sucesso!\n\n");
		return;
	}
	if((*arvore)->conteudo->cpf < c->cpf){
		inserirNoArvore(&(*arvore)->direita, c);
		return;
	}
	if((*arvore)->conteudo->cpf > c->cpf)
		inserirNoArvore(&(*arvore)->esquerda, c);
	else
		printf("Já existe um cliente cadastrado com esse cpf.\n\n\n");
}

void novoCliente(NoArvore** arvore, int cpf, char nome[30], char tel[16], char rg[10]){
	Cliente *c;
	c = (Cliente*) malloc (sizeof(Cliente));
	c->cpf = cpf;
	strcpy(c->nome, nome);
	strcpy(c->telefone, tel);
	strcpy(c->rg, rg);
	inserirNoArvore(arvore, c);
}

void encontrarPorCPF(NoArvore* arvore, NoArvore** c){
	if(!arvore || !arvore->conteudo){
		(*c)->conteudo->cpf = 0;
		return;
	}
	if(arvore->conteudo->cpf < (*c)->conteudo->cpf){
		encontrarPorCPF(arvore->direita, c);
		return;
	}
	if(arvore->conteudo->cpf > (*c)->conteudo->cpf)
		encontrarPorCPF(arvore->esquerda, c);
	else
		*c = arvore;
}

NoArvore* exibirCliente(NoArvore* arvore, int cpf, int acao){
	NoArvore *c;
	c = criaArvore();
	c->conteudo = (Cliente*) malloc (sizeof(Cliente));
	c->conteudo->cpf = cpf;
	encontrarPorCPF(arvore, &c);
	if (c->conteudo->cpf)
		switch(acao){
			case 1:
				printf("Dados do cliente:\n\n");
				printf("Nome: %s\n", c->conteudo->nome);
				printf("Telefone: %s\n", c->conteudo->telefone);
				printf("RG: %s\n\n\n", c->conteudo->rg);
				return NULL;
				break;
			case 2:
				return c;
				break;
		}
	printf("Não há cliente com esse CPF no sistema.\n\n\n");
	return NULL;
}

void alterarDadosCliente(NoArvore** arvore, int cpf, char nome[30], char tel[16], char rg[10]){
	NoArvore *c;
	c = criaArvore();
	c->conteudo = (Cliente*) malloc (sizeof(Cliente));
	c->conteudo->cpf = cpf;
	encontrarPorCPF(*arvore, &c);
	if (c->conteudo->cpf){
		strcpy(c->conteudo->nome, nome);
		strcpy(c->conteudo->telefone, tel);
		strcpy(c->conteudo->rg, rg);
		printf("Cliente editado com sucesso!\n\n\n");
	} else
		printf("Não há cliente com esse CPF no sistema.\n\n\n");
}

void antecessor(NoArvore* arvore, NoArvore** no){
	if((*no)->direita){
        antecessor(arvore, &(*no)->direita);
        return;
    }
    arvore->conteudo = (*no)->conteudo;
    arvore->contas = (*no)->contas;
    arvore = *no;
    *no = (*no)->esquerda;
    free(arvore);
}

void excluirNoArvore(NoArvore** arvore, Cliente* c){
	NoArvore* aux;
	if(!(*arvore)){
		printf("Não há cliente com esse cpf no sistema.\n\n\n");
		return;
	}
	if(c->cpf < (*arvore)->conteudo->cpf){
        excluirNoArvore(&(*arvore)->esquerda, c);
        return;
	}
    if(c->cpf > (*arvore)->conteudo->cpf){
        excluirNoArvore(&(*arvore)->direita, c);
        return;
	}
    if(!(*arvore)->direita){
        aux = *arvore;
        *arvore = (*arvore)->esquerda;
        //excluirListaDupla(aux->contas); //mudar nome para função do arquivo de listas duplas
        free(aux->conteudo);
        free(aux);
        return;
    }
    if((*arvore)->esquerda){
        antecessor(*arvore, &(*arvore)->esquerda);
        return;
    }
    aux = *arvore;
    *arvore = (*arvore)->direita;
    //excluirListaDupla(aux->contas); //mudar nome para função do arquivo de listas duplas
    free(aux->conteudo);
    free(aux);
}

void removerCliente(NoArvore** arvore, int cpf){
	NoArvore *c;
	c = criaArvore();
	c->conteudo = (Cliente*) malloc (sizeof(Cliente));
	c->conteudo->cpf = cpf;
	encontrarPorCPF(*arvore, &c);
	if (c->conteudo->cpf){
		excluirNoArvore(arvore, c->conteudo);
		printf("Cliente removido com sucesso!\n\n\n");
	}else
		printf("Não há cliente com esse CPF no sistema.\n\n\n");	
}