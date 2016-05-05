typedef struct cliente
{
    int cpf;
    char[20] nome;
    char[16] telefeone;
    ListaDupla *contas;
} Cliente*;

typedef struct noArvore
{
    Cliente *conteudo;
    NoArvore* esquerda, direita;
} NoArvore*;

void criaArvore(){

}

void inserirNoArvore(NoArvore* raiz, Cliente* c){

}

void excluirNoArvore(NoArvore* raiz, Cliente* c){

}

Cliente* encontrarPorCPF(NoArvore* raiz, int cpf){

}

void exibirCliente(Cliente c){

}

void alterarDadosCliente(int cpf, char[20] nome, char[16] tel){

}
