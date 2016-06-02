#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaDupla.h"
#include "arvore.h"

void menuCliente(NoArvore** arvore){
	char aux[30];
	printf("Selecione a operação desejada:\n");
	printf("Inserir um cliente: digite 1\n");
	printf("Editar os dados de um cliente: digite 2\n");
	printf("Exibir um cliente: digite 3\n");
	printf("Remover um cliente: digite 4\n");
	printf("Voltar ao menu principal: digite 5\n\n");
	int opcao, cpf, confirma;
	fgets(aux, sizeof(aux), stdin);
	sscanf(aux, "%d", &opcao);
	printf("\n");
	switch(opcao){
		case 1: ;
			char nome[30],tel[16],rg[10];
			printf("Digite os dados do novo cliente:\n");
			printf("CPF: ");
			fgets(aux, sizeof(aux), stdin);
			sscanf(aux, "%d", &cpf);
			printf("Nome: ");
			fgets(nome, sizeof(nome), stdin);
			printf("Telefone: ");
			fgets(tel, sizeof(tel), stdin);
			printf("RG: ");
			fgets(rg, sizeof(rg), stdin);
			printf("\n");
			novoCliente(arvore, cpf, nome, tel, rg);
			break;
		case 2:
			printf("Digite o CPF do cliente: ");
			fgets(aux, sizeof(aux), stdin);
			sscanf(aux, "%d", &cpf);
			printf("Tem certeza de que deseja editar os dados do cliente com CPF %d? (1 para sim, 2 para não)\n", cpf);
			fgets(aux, sizeof(aux), stdin);
			sscanf(aux, "%d", &confirma);
			if (confirma == 1){
				printf("\n");
				printf("Digite abaixo os novos valores que deseja para os dados do cliente:\n");
				printf("Nome: ");
				fgets(nome, sizeof(nome), stdin);
				printf("Telefone: ");
				fgets(tel, sizeof(tel), stdin);
				printf("RG: ");
				fgets(rg, sizeof(rg), stdin);
				alterarDadosCliente(arvore, cpf, nome, tel, rg);
			}
			break;
		case 3:
			printf("Digite o CPF do cliente: ");
			fgets(aux, sizeof(aux), stdin);
			sscanf(aux, "%d", &cpf);
			exibirCliente(*arvore, cpf, 1);
			break;
		case 4:
			printf("Digite o CPF do cliente: ");
			fgets(aux, sizeof(aux), stdin);
			sscanf(aux, "%d", &cpf);
			NoArvore *c;
			c = exibirCliente(*arvore, cpf, 2);
			if (!c)
				break;
			printf("Tem certeza de que deseja remover do sistema o cliente %s? (1 para sim, 2 para não)\n", c->conteudo->nome);
			fgets(aux, sizeof(aux), stdin);
			sscanf(aux, "%d", &confirma);
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

void menuConta(NoArvore** arvore){
	int opcao, cpf, confirma, numConta;
	char aux[30];
	printf("Digite o CPF do cliente: ");
	fgets(aux, sizeof(aux), stdin);
	sscanf(aux, "%d", &cpf);
	NoArvore *c;
	c = exibirCliente(*arvore, cpf, 2);
	if (!c) {
		return;
	}
	ListaDupla *contas;
	contas = c->contas;
	printf("Selecione a operação desejada:\n");
	printf("Inserir uma conta: digite 1\n");
	printf("Editar o número de uma conta: digite 2\n");
	printf("Exibir uma conta: digite 3\n");
	printf("Remover uma conta: digite 4\n");
	printf("Voltar ao menu principal: digite 5\n\n");
	fgets(aux, sizeof(aux), stdin);
	sscanf(aux, "%d", &opcao);
	printf("\n");
	switch(opcao){
		case 1:
			printf("Digite o número da nova conta: ");
			fgets(aux, sizeof(aux), stdin);
			sscanf(aux, "%d", &numConta);
			insereListaDupla(&contas, numConta);
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			break;
		default:
			printf("Opção inválida, tente novamente\n\n\n");
			break;
	}
}

void menuTipoConta(NoArvore** arvore){
	int opcao, cpf, confirma, numConta;
	float valor;
	char nome[30], aux[30];
	TipoDeConta *tipoConta;
	printf("Digite o CPF do cliente: ");
	fgets(aux, sizeof(aux), stdin);
	sscanf(aux, "%d", &cpf);
	NoArvore *c;
	c = exibirCliente(*arvore, cpf, 2);
	if (!c) {
		printf("Não há cliente com esse CPF no sistema.\n\n\n");
		return;
	}
	printf("Digite o número da conta: ");
	fgets(aux, sizeof(aux), stdin);
	sscanf(aux, "%d", &numConta);
	printf("\n");
	NoListaDupla *conta;
	conta = exibeConta(c->contas, numConta, 2);
	if (!conta) {
		printf("Esse cliente não possui uma conta com esse número.\n\n\n");
		return;
	}
	ListaSimples *lista;
	lista = conta->tiposDeConta;
	printf("Selecione a operação desejada:\n");
	printf("Creditar valor a um tipo de conta: digite 1\n");
	printf("Debitar valor de um tipo de conta: digite 2\n");
	printf("Transferir valor entre dois tipos de contas: digite 3\n");
	printf("Transferir valor entre dois tipos para outra conta: digite 4\n");
	printf("Inserir um tipo de conta: digite 5\n");
	printf("Editar os dados de um tipo de conta: digite 6\n");
	printf("Exibir um tipo de conta: digite 7\n");
	printf("Remover um tipo de conta: digite 8\n");
	printf("Voltar ao menu principal: digite 9\n\n");
	fgets(aux, sizeof(aux), stdin);
	sscanf(aux, "%d", &opcao);
	printf("\n");
	switch(opcao){
		case 1:
			printf("Digite o nome do tipo de conta: ");
			fgets(nome, sizeof(nome), stdin);
			sscanf(nome, "%[^\n]s", nome);
			tipoConta = buscarTipoConta(lista, nome);
			if (tipoConta){
				printf("Digite o valor a ser creditado: ");
				fgets(aux, sizeof(aux), stdin);
				sscanf(aux, "%f", &valor);
				movimentarSaldo(&tipoConta, valor, 1);
			} else
				printf("Não há um tipo de conta com esse nome\n");
			break;
		case 2:
			printf("Digite o nome do tipo de conta: ");
			fgets(nome, sizeof(nome), stdin);
			sscanf(nome, "%[^\n]s", nome);
			tipoConta = buscarTipoConta(lista, nome);
			if (tipoConta){
				printf("Digite o valor a ser debitado: ");
				fgets(aux, sizeof(aux), stdin);
				sscanf(aux, "%f", &valor);
				movimentarSaldo(&tipoConta, valor, 2);
			} else
				printf("Não há um tipo de conta com esse nome\n");
			break;
		case 3:
			printf("Digite o nome do tipo de conta do qual será debitado o dinheiro: ");
			fgets(nome, sizeof(nome), stdin);
			sscanf(nome, "%[^\n]s", nome);
			tipoConta = buscarTipoConta(lista, nome);
			if (tipoConta){
				char nome2[30];
				printf("Digite o nome do tipo de conta para o qual será transferido o dinheiro: ");
				fgets(nome2, sizeof(nome2), stdin);
				sscanf(nome2, "%[^\n]s", nome2);
				if (strcmp(nome,nome2)) {// Se os nomes forem diferentes a função de transferência é executada
					TipoDeConta *tipoConta2;
					tipoConta2 = buscarTipoConta(lista, nome2);
					printf("Digite o valor a ser transferido: \n");
					fgets(aux, sizeof(aux), stdin);
					sscanf(aux, "%f", &valor);
					printf("\n\n");
					TransferirSaldoTipoConta(&tipoConta, &tipoConta2, valor);
				} else
					printf("Você digitou dois tipos de conta iguais.\n");
			} else
				printf("Não há um tipo de conta com esse nome\n");
			break;
		case 4:
			printf("Escolha uma opção:\n");
			printf("Transferir de um tipo dessa conta para um tipo de outra conta: digite 1\n");
			printf("Transferir de um tipo de outra conta para um tipo dessa conta: digite 2\n\n");
			fgets(aux, sizeof(aux), stdin);
			sscanf(aux, "%d", &opcao);
			printf("\nDigite o nome do tipo dessa conta: ");
			fgets(nome, sizeof(nome), stdin);
			sscanf(nome, "%[^\n]s", nome);
			tipoConta = buscarTipoConta(lista, nome);
			if (tipoConta){
				char nome2[30];
				printf("Digite o número da outra conta: ");
				fgets(aux, sizeof(aux), stdin);
				sscanf(aux, "%d", &numConta);
				NoListaDupla *conta2;
				conta2 = exibeConta(c->contas, numConta, 2);
				if (!conta2) {
					printf("Esse cliente não tem uma conta com esse número.\n\n\n");
					break;
				}
				ListaSimples *lista2;
				lista2 = conta2->tiposDeConta;
				printf("Digite o nome do tipo da outra conta: ");
				fgets(nome2, sizeof(nome2), stdin);
				sscanf(nome2, "%[^\n]s", nome2);
				TipoDeConta *tipoConta2;
				tipoConta2 = buscarTipoConta(lista2, nome2);
				if (tipoConta2) {// Se os nomes forem diferentes a função de transferência é executada
					printf("Digite o valor a ser transferido: ");
					fgets(aux, sizeof(aux), stdin);
					sscanf(aux, "%f", &valor);
					printf("\n\n");
					if (opcao == 1)
						TransferirSaldoTipoConta(&tipoConta, &tipoConta2, valor);
					else
						TransferirSaldoTipoConta(&tipoConta2, &tipoConta, valor);
				} else
					printf("Não há um tipo de conta com esse nome na outra conta.\n");
			} else
				printf("Não há um tipo de conta com esse nome\n");
			break;
		
		case 5:
			printf("Digite o nome do novo tipo de conta: ");
			fgets(nome, sizeof(nome), stdin);
			sscanf(nome, "%[^\n]s", nome);
			printf("\n");
			novoTipoConta(&lista, nome);
			break;
		case 6:
			printf("Digite o nome do tipo de conta: ");
			fgets(nome, sizeof(nome), stdin);
			sscanf(nome, "%[^\n]s", nome);
			printf("\n");
			tipoConta = buscarTipoConta(lista, nome);
			if (tipoConta){
				editarTipoConta(tipoConta);
			} else
				printf("Não há um tipo de conta com esse nome\n");
			break;
		case 7:
			printf("Digite o nome do tipo de conta: ");
			fgets(nome, sizeof(nome), stdin);
			sscanf(nome, "%[^\n]s", nome);
			printf("\n");
			tipoConta = buscarTipoConta(lista, nome);
			if (tipoConta){
				exibirTipoConta(tipoConta);
			} else
				printf("Não há um tipo de conta com esse nome\n");
			break;
		case 8:
			printf("Digite o nome do tipo de conta: ");
			fgets(nome, sizeof(nome), stdin);
			sscanf(nome, "%[^\n]s", nome);
			tipoConta = buscarTipoConta(lista, nome);
			if (!tipoConta){
				printf("Não há um tipo de conta com esse nome\n");
				break;
			}
			printf("\nTem certeza de que deseja remover dessa conta o tipo %s? (1 para sim, 2 para não)\n", tipoConta->descricao);
			fgets(aux, sizeof(aux), stdin);
			sscanf(aux, "%d", &confirma);
			if (confirma == 1) {
				removerNoLista(&lista, &tipoConta);
			}
			break;
		case 9:
			break;
		default:
			printf("Opção inválida, tente novamente\n\n\n");
			break;
	}
}

void menuPrincipal(NoArvore** arvore){
	printf("Escolha uma das opções a seguir para continuar:\n");
	printf("Operações sobre um cliente: digite 1\n");
	printf("Operações sobre as contas de um cliente: digite 2\n");
	printf("Operações sobre um tipo de conta de um cliente: digite 3\n");
	printf("Encerrar programa: digite 4\n\n");
	char aux[30];
	int opcao;
	fgets(aux, sizeof(aux), stdin);
	sscanf(aux, "%d", &opcao);
	printf("\n");
	switch(opcao){
		case 1:
			menuCliente(arvore);
			break;
		case 2:
			menuConta(arvore);
			break;
		case 3:
			menuTipoConta(arvore);
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
