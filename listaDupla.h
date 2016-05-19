typedef struct noListaDupla
{
	int numConta;
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
		/* code */
	}
}