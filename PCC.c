/*Bibliotecas*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

/*Constantes*/
#define N 50

/*Estrutura do registro*/
typedef struct {
	int numFrase;
	char Frase[N];
	int escoCine;
	char item1[N];
	int escoAudi;
	char item2[N];
	int escoVisu;
	char item3[N];
	int escoDigi;
	char item4[N];
}registro;


/*Variáveis globais*/
char nomeuser[N];
char prontuario[N];
char nomeArq[N];
registro relaux;

/*Ponteiro para o arquivo .dat e .txt*/
FILE * arqdat; 
FILE * relatxt;


/*Protótipos das funções*/
int main();
void chamaMenu();
void fazTeste();



/*Corpo do programa*/
int main(){
	setlocale(LC_ALL, "");
	/*Variáveis locais*/
	
	/*Menu inicial*/
	printf("\nDIGITE O SEU NOME:      ");
	fflush(stdin);
	gets(nomeuser);
	/*Verificar se há espaço em branco e converte para maiúsculo*/
	for(int i = 0; i < strlen(nomeuser); i++){
		nomeuser[i] = toupper(nomeuser[i]);
		if(nomeuser[i] == ' ')
			nomeuser[i] = '_';		
		}
			
	/*Abre o menu do MASTER*/
	if(strcmp(nomeuser, "MASTER") == 0)	{
		chamaMenu();	
	}
	
	else{	
		printf("\nDIGITE SEU PRONTUÁRIO:  ");
		fflush(stdin);
		gets(prontuario);
		/*Converte tudo para maiúsculo*/
		for(int i = 0; i < strlen(prontuario); i++){ 
			prontuario[i] = toupper(prontuario[i]);		
		}
	
		
	}
	
	/*Gera nome do arquivo*/
	for(int i = 0; i < strlen(nomeArq); i++){
		nomeArq[i] = '\0'; /*Limpa cada caractere do nome*/
	}
	strcat(nomeArq, "RESULTADO");
	strcat(nomeArq, "_");
	strcat(nomeArq, nomeuser);
	strcat(nomeArq, "_");
	strcat(nomeArq, prontuario);
	strcat(nomeArq, ".TXT");
	
	/*Abrir arquivo .txt*/
	arq = fopen(nomeArq, "w");
	
	/*Testar se arquivo foi criado*/
	if(arq == NULL){ 
		printf("Erro na abertura do arquivo.");
	return 1;
	}

	return(0);
}

/*Funções*/
void chamaMenu(){
	
	char escolha;

	do{
	/*Limpa a tela*/
	system("cls");
		printf("==================================================\n");
		printf("	TESTE DO SISTEMA REPRESENTACIONAL	\n");
		printf("==================================================\n");
		printf("	1 - Cadastrar Questionário\n");
		printf("	2 - Visualizar Questionário\n");
		printf("	3 - Realizar Teste\n");
		printf("	4 - Sobre o Teste\n");
		printf("	F - Fim\n\n\t");
		scanf("%c", &escolha);
		
		switch(escolha)
		{
			case '1' : 
			{
				system("cls");
				/*Gera relatório .TXT*/
				relatxt = fopen("TESTE_SISTEMA_REPRESENTACIONAL.TXT", "w");
				/*Testa se gerou arquivo*/
				if(relatxt == NULL){
					printf("Erro ao gerar relatório");
					getch();
					exit(0);
				}
				
				/*Gera arquivo .DAT*/
				arqdat = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
				/*Testa se gerou arquivo*/
				if(arqdat == NULL){
					printf("Erro ao gerar relatório");
					getch();
					exit(0);
				}
				
				getche();
				break;
			}
			case '2' : 
			{
				system("cls");
				printf("opcao2\n"); 
				getche();
				break;
			}
			case '3' : 
			{
				/*Aplicação do questionário*/
				system("cls");
				fazTeste();
				break;
			}
			case '4' :
			{
				system("cls");
				printf("opcao4"); 
				getche();
				break;
			}
			case 'f' : 
			{
				break;
			}
			default :
			{
				printf("Essa não é uma escolha válida");
			}
		}
	}
	while(escolha != 'f');
}
void fazTeste(){
	
	
	printf("Nas frases a seguir, pontue com:\n4 para a que melhor te descreve;\n3 para próxima melhor descrição;\n2 para a próxima melhor;\n1 para aquela que menos descreve você.\n\n");
	printf("1. Eu tomo decisões baseadas em:\n");
	printf("a) Intuição\nb) O que me soa melhor\nc) O que me parece melhor\nd) Um estudo preciso e minucioso do assunto\n\n");
	printf("[a] -> 4\n[b] -> 3\n[c] -> 2\n[d] -> 1\n\n");
	getche();
}
