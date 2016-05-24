#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void menuCliente(NoArvore* arvore){
	printf("Selecione a operação desejada:\n");
	printf("Inserir um cliente: digite 1\n");
	printf("Editar os dados de um cliente: digite 2\n");
	printf("Remover um cliente: digite 3\n");
	printf("Exibir um cliente: digite 4\n");
	printf("Voltar ao menu principal: digite 5\n");
	int opcao, cpf;
	scanf("%d",&opcao);
	switch(opcao){
		case 1: ;
			char nome[30],tel[16],rg[10];
			printf("Digite os dados do novo cliente\n");
			printf("CPF: ");
			scanf("%d", &cpf);
			printf("Nome: ");
			scanf("%s", nome);
			//fgets(nome, sizeof(nome), stdin);
			printf("Telefone: ");
			scanf("%s", tel);
			//fgets(tel, sizeof(tel), stdin);
			printf("RG: ");
			scanf("%s", rg);
			//fgets(rg, sizeof(rg), stdin);
			novoCliente(arvore, cpf, nome, tel, rg);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			printf("Digite o CPF do cliente\n");
			scanf("%d",&cpf);
			exibirCliente(*arvore,cpf);
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("Opção inválida, tente novamente");
			break;
	}
}

void menuPrincipal(NoArvore* arvore){
	printf("Escolha uma das opções a seguir para continuar:\n");
	printf("Operações sobre um cliente: digite 1\n");
	printf("Operações sobre as contas de um cliente: digite 2\n");
	printf("Operações sobre uma conta específica de um cliente: digite 3\n");
	printf("Encerrar programa: digite 4\n");
	int opcao;
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
			menuCliente(arvore);
			break;
		case 2:
			//menuContas();
			break;
		case 3:
			//menuConta();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Opção inválida, tente novamente\n");
			break;
	}
	menuPrincipal(arvore);
}

int main(){
	NoArvore arvore;
	arvore = criaArvore();
	/*int cpf;
	char nome[30],tel[16],rg[10];
	printf("AAAAAAAAAAA ");
	cpf = 12345;
	strcpy(nome, "pafuncio");
	strcpy(tel, "99999-9999");
	strcpy(rg, "999.999");
	printf("AAAAAAAAAAA ");
	novoCliente(&arvore, cpf, nome, tel, rg);*/
	menuPrincipal(&arvore);
	return 0;
}
