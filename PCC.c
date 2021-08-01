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


/*Vari�veis globais*/
char nomeuser[N];
char prontuario[N];
char nomeArq[N];
registro relaux;

/*Ponteiro para o arquivo .dat e .txt*/
FILE * arqdat; 
FILE * relatxt;


/*Prot�tipos das fun��es*/
int main();
void chamaMenu();
void fazTeste();



/*Corpo do programa*/
int main(){
	setlocale(LC_ALL, "");
	/*Vari�veis locais*/
	
	/*Menu inicial*/
	printf("\nDIGITE O SEU NOME:      ");
	fflush(stdin);
	gets(nomeuser);
	/*Verificar se h� espa�o em branco e converte para mai�sculo*/
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
		printf("\nDIGITE SEU PRONTU�RIO:  ");
		fflush(stdin);
		gets(prontuario);
		/*Converte tudo para mai�sculo*/
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

/*Fun��es*/
void chamaMenu(){
	
	char escolha;

	do{
	/*Limpa a tela*/
	system("cls");
		printf("==================================================\n");
		printf("	TESTE DO SISTEMA REPRESENTACIONAL	\n");
		printf("==================================================\n");
		printf("	1 - Cadastrar Question�rio\n");
		printf("	2 - Visualizar Question�rio\n");
		printf("	3 - Realizar Teste\n");
		printf("	4 - Sobre o Teste\n");
		printf("	F - Fim\n\n\t");
		scanf("%c", &escolha);
		
		switch(escolha)
		{
			case '1' : 
			{
				system("cls");
				/*Gera relat�rio .TXT*/
				relatxt = fopen("TESTE_SISTEMA_REPRESENTACIONAL.TXT", "w");
				/*Testa se gerou arquivo*/
				if(relatxt == NULL){
					printf("Erro ao gerar relat�rio");
					getch();
					exit(0);
				}
				
				/*Gera arquivo .DAT*/
				arqdat = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
				/*Testa se gerou arquivo*/
				if(arqdat == NULL){
					printf("Erro ao gerar relat�rio");
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
				/*Aplica��o do question�rio*/
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
				printf("Essa n�o � uma escolha v�lida");
			}
		}
	}
	while(escolha != 'f');
}
void fazTeste(){
	
	
	printf("Nas frases a seguir, pontue com:\n4 para a que melhor te descreve;\n3 para pr�xima melhor descri��o;\n2 para a pr�xima melhor;\n1 para aquela que menos descreve voc�.\n\n");
	printf("1. Eu tomo decis�es baseadas em:\n");
	printf("a) Intui��o\nb) O que me soa melhor\nc) O que me parece melhor\nd) Um estudo preciso e minucioso do assunto\n\n");
	printf("[a] -> 4\n[b] -> 3\n[c] -> 2\n[d] -> 1\n\n");
	getche();
}
