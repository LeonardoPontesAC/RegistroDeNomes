#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //respons�vel por cuidar das strings

int registro(){
	
	setlocale(LC_ALL, "Portuguese"); //defini��o da lingua
	
	int volta=1;
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	while(volta==1){
	
		printf(" Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); //copia os valores das string
		
		FILE *file;                 //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo
		
		fprintf(file,cpf); //salva em "file" a vari�vel cpf
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //abre o arquivo para editar
		fprintf(file, ", ");
		fclose(file);
		
		printf(" Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a"); //abre o arquivo para editar
		fprintf(file, nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, " ");
		fclose(file);
		
		printf(" Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ", ");
		fclose(file);
		
		printf(" Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		
		system("pause");
		
		system("cls");
		printf(" \n Cadastrar outro usu�rio? \n\n");
		printf(" 1 - SIM \n");
		printf(" 2 - N�O \n");
		scanf("%d", &volta);
		system("cls");	
	}	
}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese"); //defini��o da lingua
	
	int volta=1;
	
	char cpf[40];
	char conteudo[200];
	
	while(volta==1){
	
		printf(" Digite o cpf a ser consultado: ");
		scanf("%s", cpf);
		
		FILE *file; //parte da biblioteca que consulta arquivos
		file = fopen(cpf, "r");
		
		if(file == NULL){
			printf("\n Usu�rio n�o localizado \n\n");
		}
		
		while(fgets(conteudo, 200, file) != NULL){
			printf("\n Usu�rio localizado: \n\n");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		fclose(file);
		
		system("pause");
		
		system("cls");
		printf(" \n Consultar outro usu�rio? \n\n");
		printf(" 1 - SIM \n");
		printf(" 2 - N�O \n");
		scanf("%d", &volta);
		system("cls");	
	}		
}

int deletar(){
	
	int volta=1;
	
	char cpf[40];
	
	while(volta==1){
	
		printf(" Digite o cpf a ser deletado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL){
			printf("\n Usu�rio n�o localizado \n\n");
			system("pause");		
		}
		else{
			fclose(file);
			remove(cpf);
			printf("\n Usu�rio deletado \n\n");
			system("pause");
		}
		
		system("cls");
		printf(" \n Deletar outro usu�rio? \n\n");
		printf(" 1 - SIM \n");
		printf(" 2 - N�O \n");
		scanf("%d", &volta);
		system("cls");
	}
}
	


int main(){
	int opcao=0;
	int laco=1;
	int sair=0;
	
	for(laco=1;laco=1;){
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //defini��o da lingua
		
		printf("\n Cart�rio da EBAC \n");
		printf("\n Ecolha a op��o desejada no menu: \n \n");
		printf("	1 - Registrar nome \n");
		printf("	2 - Consultar nome \n");
		printf("	3 - Deletar nome \n"); // ou /t
		printf("	4 - Sair \n");
		printf("\n Op��o:");
		
		scanf("%d", &opcao); //"%d" para ler variavel inteira
		
		system("cls"); //limpa a tela
		
		switch(opcao){
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf(" Deseja realmente sair do programa? \n");
			printf(" 1 - SIM \n");
			printf(" 2 - N�O \n");
			scanf("%d", &sair);
			system("cls");
			
			if(sair == 2){
				printf("");
				system("cls");
			}
			else{
				printf(" Volte sempre! \n");
				return 0; //quebra o c�digo e finaliza o programa
			}
			break;
			
			default:
			printf(" Op��o invalida!!! \n");
			system("pause");
			break;
		}	
	}
	printf("\n\n\n\n Esse Software pertence a Miyako Vollerei \n\n\n\n");
}
