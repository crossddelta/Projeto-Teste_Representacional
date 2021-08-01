/*Bibliotecas*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

/*Constantes*/
#define N 100

/*Variáveis globais*/
char nomeuser[N];
char prontuario[N];
char nomeArq[N];

/*Protótipos das funções*/
int  main();
void chamaMenu();
void fazTeste();

/*Estrutura do registro do teste*/
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

/*Ponteiro para o arquivo .dat e .txt*/
registro relaux;

/*Abrir arquivo .txt*/
/*arq = fopen(nomeArq, "w");*/
/*Testar se arquivo foi criado*/
/*if(arq == NULL){ 
	printf("Erro na abertura do arquivo.");
return 1;
};*/

/*Criando tabela de 5 elementos com os dados da struct registro*/
registro varFrases[5] =   {
						  {1, "Eu tomo decisões importantes baseado(a) em",         0, "intuição",                                                       0, "o que me soa melhor",                                     0, "o que me parece melhor",                                    0, "um estudo preciso e minucioso do assunto"							  },
						  {2, "Durante uma discussão sou mais influenciado(a) por", 0, "se eu entro em contato ou não com o sentimentos reais do outro", 0, "o tom da voz da outra pessoa",                            0, "se eu posso ou não ver o argumento da outra pessoa",        0,	"a lógica do argumento da outra pessoa"   							  },
						  {3, "Eu comunico mais facilmente o que se passa comigo" , 0, "pelos sentimentos que compartilho",                              0, "pelo tom da minha voz",                                   0, "do modo como me visto e aparento",                          0, "pelas palavras que escolho"    		                                  },
						  {4, "É muito fácil para mim",                             0, "Escolher os móveis mais confortáveis",                           0, "achar o volume e a sintonia ideias em um sistema de som", 0, "escolher as combinações de cores mais ricas e atraentes",   0, "selecionar o ponto mais relevante relativo a um assunto interessante"  },
						  {5, "Eu me percebo assim", 								0, "Eu sou muito sensível à maneira como a roupa veste o meu corpo", 0, "se eu estou muito em sintonia com os sons dos ambientes", 0, "eu respondo fortemente às cores e à aparência de uma sala", 0, "se sou muito capaz de raciocinar com fatos e dados novos"        	  }
};

/*Corpo do programa*/
int main(){
	setlocale(LC_ALL, "");
	
/*Tela de login*/
	printf("\nDIGITE O SEU NOME:      ");
	fflush(stdin);
	gets(nomeuser);
	
/*Verificar se há espaço em branco e converte para maiúsculo para facilitar verificação*/
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
	
/*Gera nome do arquivo a partir dos dados inseridos no login e salva em uma variável*/
	for(int i = 0; i < strlen(nomeArq); i++){
		nomeArq[i] = '\0'; /*Limpa cada caractere do nome*/
	}
	strcat(nomeArq, "RESULTADO");
	strcat(nomeArq, "_");
	strcat(nomeArq, nomeuser);
	strcat(nomeArq, "_");
	strcat(nomeArq, prontuario);
	strcat(nomeArq, ".TXT");

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
	
switch(escolha)	{
	case '1' : {
		system("cls");
		
		/*Gera arquivo .DAT*/
		FILE * arquivodat; 
		arquivodat = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");
		
		/*Checa se gerou arquivo*/
		if(arquivodat == NULL){
		printf("Erro ao gerar relatório. \n\nPressione qualquer tecla para sair.");
		getch();
		exit(0);
		}
		
		/*Gravar as frases registradas no arquivo criado*/
		for(int i = 0; i < 5; i++){
			fwrite(&varFrases[i], sizeof(varFrases)[i], 1, arquivodat);
		}
		fclose(arquivodat);
		printf("Êxito ao gerar arquivo!");
		getche();
		
	break;
	}

	case '2' : {
		system("cls");
		FILE * arquivodat;
		arquivodat = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
		
		FILE * relatoriotxt;
		relatoriotxt = fopen("QUESTIONÁRIO_1.TXT", "w");
		
		/*Checa se o arquivo txt foi criado*/
		if(relatoriotxt == NULL){
			printf("Erro ao gerar arquivo .txt. \n\nPressione qualquer tecla para sair.");
			getch();
			exit(0);
		}
		
		/*Transferir dados do .dat para o .txt*/
		registro varFrasestxt[5];
		registro varaux;
		
		/*Checa se há arquivo .dat para se copiar*/
		if(arquivodat == NULL){
			printf("Não há nenhum teste registrado no sistema. \n\nPressione qualquer tecla para sair.");
			getch();
			exit(0);
		}
		
		getche();
		
	break;
		}

	case '3' : {
		/*Aplicação do questionário*/
		system("cls");
		fazTeste();
		
	break;
		}

	case '4' : {
		system("cls");
		printf("opcao4"); 
		getche();
		
	break;
		}

	case 'f' : {
		
	break;
		}

	default :{
		printf("Essa não é uma escolha válida");
		}
} /*Fim do switch*/
} /*Fim do Do*/

while(escolha != 'f');

}

void fazTeste(){
	
	
	printf("Nas frases a seguir, pontue com:\n4 para a que melhor te descreve;\n3 para próxima melhor descrição;\n2 para a próxima melhor;\n1 para aquela que menos descreve você.\n\n");
	printf("1. Eu tomo decisões baseadas em:\n");
	printf("a) Intuição\nb) O que me soa melhor\nc) O que me parece melhor\nd) Um estudo preciso e minucioso do assunto\n\n");
	printf("[a] -> 4\n[b] -> 3\n[c] -> 2\n[d] -> 1\n\n");
	getche();
}
