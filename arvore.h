typedef struct cliente {
    int cpf;
    char[20] nome;
    char[16] telefeone;
    char[10] rg;
} Cliente;

typedef struct noArvore {
    Cliente *conteudo;
    ListaDupla *contas;
    struct noArvore *esquerda, *direita;
} NoArvore;

NoArvore criaArvore(){
	NoArvore novaArvore = (NoArvore *) malloc(sizeof(NoArvore));
	novaArvore.conteudo = NULL;
	novaArvore.ListaDupla = NULL;
	novaArvore.esquerda = NULL;
	novaArvore.direita = NULL;
	return novaArvore;
}

void inserirNoArvore(NoArvore* raiz, Cliente* c){
	
}

void excluirNoArvore(NoArvore* raiz, Cliente* c){

}

Cliente encontrarPorCPF(NoArvore* raiz, int cpf){

}

void exibirCliente(Cliente c){

}

void alterarDadosCliente(int cpf, char[20] nome, char[16] tel){

}
