#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void menuPrincipal(){
	printf("Escolha uma das opções a seguir para continuar:\n");
	printf("Operações sobre um cliente: digite 1\n");
	printf("Operações sobre as contas de um cliente: digite 2\n");
	printf("Operações sobre uma conta específica de um cliente: digite 3\n");
	printf("Encerrar programa: digite 4");
	int opcao;
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
			menuCliente();
			break;
		case 2:
			menuContas();
			break;
		case 3:
			menuConta();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Opção inválida, tente novamente");
			break;
	}
}

int main(){
	printf("Bem vindo! ");
	menuPrincipal();
	return 0;
}
