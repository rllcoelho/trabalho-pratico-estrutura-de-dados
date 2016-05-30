#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void menuCliente(NoArvore** arvore){
	printf("Selecione a operação desejada:\n");
	printf("Inserir um cliente: digite 1\n");
	printf("Editar os dados de um cliente: digite 2\n");
	printf("Exibir um cliente: digite 3\n");
	printf("Remover um cliente: digite 4\n");
	printf("Voltar ao menu principal: digite 5\n\n");
	int opcao, cpf, confirma;
	scanf("%d",&opcao);
	printf("\n");
	switch(opcao){
		case 1: ;
			char nome[30],tel[16],rg[10];
			printf("Digite os dados do novo cliente:\n");
			printf("CPF: ");
			scanf("%d", &cpf);
			printf("Nome: ");
			scanf("%s", nome);
			printf("Telefone: ");
			scanf("%s", tel);
			printf("RG: ");
			scanf("%s", rg);
			printf("\n");
			novoCliente(arvore, cpf, nome, tel, rg);
			break;
		case 2:
			printf("Digite o CPF do cliente: ");
			scanf("%d",&cpf);
			printf("Tem certeza de que deseja editar os dados do cliente com CPF %d? (1 para sim, 2 para não)\n", cpf);
			scanf("%d", &confirma);
			if (confirma == 1){
				printf("\n");
				printf("Digite abaixo os novos valores que deseja para os dados do cliente:\n");
				printf("Nome: ");
				scanf("%s", nome);
				printf("Telefone: ");
				scanf("%s", tel);
				printf("RG: ");
				scanf("%s", rg);
				alterarDadosCliente(arvore, cpf, nome, tel, rg);
			}
			break;
		case 3:
			printf("Digite o CPF do cliente: ");
			scanf("%d",&cpf);
			exibirCliente(*arvore,cpf);
			break;
		case 4:
			printf("Digite o CPF do cliente: ");
			scanf("%d",&cpf);
			printf("Tem certeza de que deseja remover do sistema o cliente com CPF %d? (1 para sim, 2 para não)\n", cpf);
			scanf("%d", &confirma);
			if (confirma == 1){
				printf("\n");
				removerCliente(arvore, cpf);
			}
			break;
		case 5:
			break;
		default:
			printf("Opção inválida, tente novamente\n\n\n");
			menuCliente(arvore);
			break;
	}
}

void menuPrincipal(NoArvore** arvore){
	printf("Escolha uma das opções a seguir para continuar:\n");
	printf("Operações sobre um cliente: digite 1\n");
	printf("Operações sobre as contas de um cliente: digite 2\n");
	printf("Operações sobre uma conta específica de um cliente: digite 3\n");
	printf("Encerrar programa: digite 4\n\n");
	int opcao;
	scanf("%d",&opcao);
	printf("\n");
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
			printf("Opção inválida, tente novamente\n\n\n");
			break;
	}
	menuPrincipal(arvore);
}

int main(){
	NoArvore* arvore;
	arvore = criaArvore();
	menuPrincipal(&arvore);
	return 0;
}
