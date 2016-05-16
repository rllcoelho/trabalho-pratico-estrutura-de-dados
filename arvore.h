typedef struct cliente {
    int cpf;
    char nome[20], telefeone[16], rg[10];
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

void inserirNoArvore(NoArvore* raiz, Cliente* c){
	
}

void excluirNoArvore(NoArvore* raiz, Cliente* c){

}

Cliente encontrarPorCPF(NoArvore* raiz, int cpf){

}

void exibirCliente(Cliente c){

}

void alterarDadosCliente(int cpf, char nome[20], char tel[16]){

}
