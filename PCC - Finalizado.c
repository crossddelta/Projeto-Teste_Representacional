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
void geraQuestionario();
void visuQuestionario();
void fazTeste();
void sobreTeste();

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
		geraQuestionario();

		/*Converte tudo para maiúsculo*/
		for(int i = 0; i < strlen(prontuario); i++){
		 
			prontuario[i] = toupper(prontuario[i]);		
		}
		fazTeste();
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
fflush(stdin);
escolha = toupper(escolha);
	
switch(escolha)	{
	case '1' : {
		system("cls");
		geraQuestionario();
	break;
	}

	case '2' : {
		system("cls");
		visuQuestionario();
		getch();
		fflush(stdin);
	break;
		}

	case '3' : {
		system("cls");
		fazTeste();
		getch();
		fflush(stdin);
	break;
		}

	case '4' : {
		system("cls");
		sobreTeste();
		getch();
		fflush(stdin);																		

	break;
		}

	case 'F' : {
		printf("Programa encerrado com sucesso!\n\nPressione qualquer tecla para sair.");
		getch();
		exit(0);
		}

	default :{
		system("cls");
		printf("ERRO AO ESCOLHER.");
		getch();
		}
} /*Fim do switch*/
} /*Fim do Do*/

while(escolha != 'F');

}

void geraQuestionario(){
			
	/*Gera arquivo .DAT*/
	FILE * arquivodat; 
	arquivodat = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");

	/*Checa se gerou arquivo*/
	if(arquivodat == NULL){
		printf("Erro ao gerar relatório. \n\nPressione qualquer tecla para sair.");
		getch();
		fflush(stdin);
		exit(0);
	}

	/*Gravar as frases registradas no arquivo criado*/
	for(int i = 0; i < 5; i++){
	fwrite(&varFrases[i], sizeof(varFrases)[i], 1, arquivodat);
	/*Checa se houve erros na gravação*/
	if(ferror(arquivodat)){
		printf("Erro ao gravar o %dº registro!", i+1);
		getch();
		fflush(stdin);
		break;
		}
	}

	fclose(arquivodat);
	printf("Êxito ao gerar arquivo!");
	getch();
	fflush(stdin);

}

void visuQuestionario(){
	FILE * arquivodat;
	arquivodat = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
	
	FILE * relatoriotxt;
	relatoriotxt = fopen("QUESTIONÁRIO_1.TXT", "w");
		
	/*Checa se o arquivo txt foi criado*/
	if(relatoriotxt == NULL){
		printf("Erro ao gerar arquivo .txt. \n\nPressione qualquer tecla para sair.");
		getch();
		fflush(stdin);
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

	/*Cabeçalho da tabela*/
	char nrofrase[] = {"NroFrase"};
	char frase[] = {"Frase"};
	char Cinestesico[] = {"C"};
	char Auditivo[] = {"A"};
	char Visual[] = {"V"};
	char Digital[] = {"D"};
	char item_1[] = {"item_1"};
	char item_2[] = {"item_2"};
	char item_3[] = {"item_3"};
	char item_4[] = {"item_4"};

	/*Grava o cabeçalho no .txt*/
	fprintf(relatoriotxt, "================================================================================================================================================================================================================================================================================================================================================================================================================="  );
	fprintf(relatoriotxt, "\n");
	fprintf(relatoriotxt, "\n                                                              QUESTIONÁRIO                                                                                                                         QUESTIONÁRIO                                                                                                                         QUESTIONÁRIO                                                             ");
	fprintf(relatoriotxt, "\n");
	fprintf(relatoriotxt, "\n=================================================================================================================================================================================================================================================================================================================================================================================================================");
	fprintf(relatoriotxt, "\n%-7s |%-75s %-2s %-75s %-2s %-75s %-2s %-75s %-2s %-75s", nrofrase, frase, Cinestesico, item_1, Auditivo, item_2, Visual, item_3, Digital, item_4);
	fprintf(relatoriotxt, "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	/*Lê o arquivo .dat*/
	for(int i = 0; !feof(arquivodat); i++){
		fread(&varaux, sizeof(varaux), 1, arquivodat);
	
	if(ferror(arquivodat)){
		printf("Erro ao ler arquivo de dados. \n\nPressione qualquer tecla para sair.");
		getch();
		fflush(stdin);
	break;
	}

	/*Testar se chegou no fim do arquivo (eof)*/
	if(!feof(arquivodat)){
		varFrasestxt[i] = varaux;
		
	/*Grava os dados lidos no .txt*/
	fprintf(relatoriotxt, "    %d    |%-75s %-2d %-75s %-2d %-75s %-2d %-75s %-2d %-75s\n", varFrasestxt[i].numFrase, varFrasestxt[i].Frase, varFrasestxt[i].escoCine, varFrasestxt[i].item1, varFrasestxt[i].escoAudi, varFrasestxt[i].item2, varFrasestxt[i].escoVisu, varFrasestxt[i].item3, varFrasestxt[i].escoDigi, varFrasestxt[i].item4);		
		}
	}
	fclose(relatoriotxt);
	fclose(arquivodat);
	printf("Êxito ao gerar arquivo de texto.\n\nPressione qualquer tecla para visualizá-lo.");
	getch();
	fflush(stdin);
	
	/*Abre o arquivo txt para visualização*/
	system("QUESTIONÁRIO_1.TXT");
}

void fazTeste(){
	/*Variáveis locais*/
	int indice = 0;
	char perfildominante[12];
	/*Abre arquivo .dat para fazer o teste*/
	FILE * arquivodat;
	arquivodat = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");	

	/*Checa se há arquivo válido para fazer o teste*/
	if(arquivodat == NULL){
		printf("Erro ao abrir arquivo.\n\nPressione qualquer tecla para sair.");
		getch();
		exit(0);
	}
	
	/*Variáveis para armazenar o questionário*/
	registro varFrasestxt[5];
	registro varaux;
	
	/*Loop for para ler todos os registros do arquivo de dados*/
	while(!feof(arquivodat)){
		fread(&varaux, sizeof(varaux), 1, arquivodat);
	
	/*Checa se houve erro na leitura dos registros*/
	if(ferror(arquivodat)){
		printf("Erro na leitura no registro. \n\nPressione qualquer tecla para sair.");
		getch();
	break;
	}
	/*Testa se chegou no EOF, se não, grava os dados da variável auxiliar no vetor de registro*/
	if(!feof(arquivodat)){
	
	varFrasestxt[indice] = varaux;
	
	indice++;	
		}
	}
	
	/*Fecha o arquivo após ler todos os registros*/
	fclose(arquivodat);
	
	/*Início do teste*/
	/*Variáveis que armazenarão os valores do teste*/
	int totalCine = 0, totalAudi = 0, totalVisu = 0, totalDigi = 0;
	
	/*Loop para ler o teste*/
	for(int i = 0; i < 5; i++){
	
	/*Variável temporária para coletar respostas*/
	int valor[4] = {-5, -4, -3, -2};
		/*Instruções do teste*/
		printf("Nas frases a seguir, pontue com:\n");
		printf("-> 4 a que melhor descreve você\n");
		printf("-> 3 a próxima melhor descrição\n");
		printf("-> 2 a proxima melhor\n");
		printf("-> 1 aquela que menos descreve você\n");
		
		system("cls");
		
		printf("\n%d - %s\n", varFrasestxt[i].numFrase, varFrasestxt[i].Frase);
		printf("a) %s\n", varFrasestxt[i].item1);
		printf("b) %s\n", varFrasestxt[i].item2);
		printf("c) %s\n", varFrasestxt[i].item3);
		printf("d) %s\n", varFrasestxt[i].item4);
	
	/*Loop para capturar a resposta de cada frase, sem repetições e valores não permitidos*/
		for(int j = 1; j < 5; j++){
			printf("\n[%c]--> ", 96+j);
			scanf("%d", &valor[j-1]);
				if(valor[j-1] < 1 || valor[j-1] > 4){
					printf("Não é permitido inserir valores maiores que 4 ou menores que 1, tente novamente!\n");
					j--;
				}
				if(valor[1] == valor[0] || valor[2] == valor[1] || valor[2] == valor[0] || valor[3] == valor[2] || valor[3] == valor[1] || valor[3] == valor[0]){
					printf("Não é permitido repetir valores, tente novamente!");
					j--;
				}
		}
		/*Soma as respostas para obter perfil*/
		totalCine += valor[0];
		totalAudi += valor[1];
		totalVisu += valor[2];
		totalDigi += valor[3];
	}
	/*Calcular o percentual de cada característica*/
	totalCine *= 2;
	strcpy(perfildominante, "Cinestésico");
	
	totalAudi *= 2;
	if(totalAudi > totalCine) strcpy(perfildominante, "Auditivo");
	
	totalVisu *= 2;
	if(totalVisu > totalAudi && totalVisu > totalCine) strcpy(perfildominante, "Visual");
	
	totalDigi *= 2;
	if(totalDigi > totalVisu && totalDigi > totalAudi && totalDigi > totalCine) strcpy(perfildominante, "Digital");
	
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
	
	/*Abre arquivo com o nome do participante do teste*/
	FILE * arquivoTeste;
	arquivoTeste = fopen(nomeArq, "w");
	
	/*Checa se criou arquivo*/
	if(arquivoTeste == NULL){
		printf("Erro ao gerar arquivo. \n\nPressione qualquer tecla para sair.");
		getch();
		exit(0);
	}
	
	/*Gravar resultado do teste no arquivo*/
	fprintf(arquivoTeste, "==================================================== PERFIL REPRESENTACIONAL DE %s ================================================\n", nomeuser);
    fprintf(arquivoTeste, "           %d%% Cinestésico                  %d%% Auditivo                     %d%% Visual                   %d%% Digital\n", totalCine, totalAudi, totalVisu, totalDigi);
    fprintf(arquivoTeste, "=========================================================================================================================================\n");
    fprintf(arquivoTeste, "Algumas pessoas captam melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas auditivas.\n");
    fprintf(arquivoTeste, "Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as digitais.\n");
    fprintf(arquivoTeste, "As cinestésicas aprendem melhor por meio das sensações táteis, como o tato, à temperatura, a umidade, as sensações internas e as emoções.\n");
    fprintf(arquivoTeste, "Já as pessoas visuais aprendem melhor quando se valendo da visão.\n\n");
    fprintf(arquivoTeste, "=========================================================================================================================================\n");
    fprintf(arquivoTeste, "Seu perfil é %s\n", perfildominante);
    fprintf(arquivoTeste, "=========================================================================================================================================\n");
	
	/*Fecha arquivo e exibe o .txt*/
	fclose(arquivoTeste);
	system(nomeArq);
	fflush(stdin);
}

void sobreTeste(){
	/*Cria arquivo para o referencial teórico*/
	FILE * refteo;
	refteo = fopen("REFERENCIAL_TEORICO.TXT", "w+");
	
	/*Checa se criou o arquivo para o referencial*/
	if(refteo == NULL){
		printf("Erro ao criar arquivo!\n\nPressione qualquer tecla para sair.");
		getch();
		exit(0);
	}
	
	/*Grava o conteúdo no arquivo criado*/
	fprintf(refteo, "-------------------------------------------------------------------\n");
	fprintf(refteo, "                         Sobre o teste\n");
	fprintf(refteo, "-------------------------------------------------------------------\n");
	fprintf(refteo, "Segundo Albert Merabian, em seu livro 'Silent Messages',\n");
	fprintf(refteo, "o poder de influência das palavras não passa de 7%%,\n");
	fprintf(refteo, "enquanto a forma como as palavras são ditas e a fisiologia\n");
	fprintf(refteo, "representam 38%% e 55%% deste poder, respectivamente.\n\n");
	fprintf(refteo, "Para Merabian, 55%% do impacto da comunicação é não-verbal.\n");
	fprintf(refteo, "Corresponde à postura, gestos e contato visual da pessoa\n");
	fprintf(refteo, "enquanto se comunica.\n\n");
	fprintf(refteo, "O tom da voz representa 38%% do impacto da comunicação.\n\n");
	fprintf(refteo, "Por fim, as palavras propriamente ditas detém 7%% do impacto\n");
	fprintf(refteo, "da comunicação.\n");
	fprintf(refteo, "Assim sendo, conclui Merabian, não é o que dizemos, mas como\n");
	fprintf(refteo, "dizemos que faz a diferença na comunicação.\n");
	fprintf(refteo, "As portas da percepção são os nossos sentidos, nossos olhos,\n");
	fprintf(refteo, "nariz, ouvidos, boca e pele, nossos únicos ponos de contato com\n");
	fprintf(refteo, "o mundo exterior.\n");														
	fprintf(refteo, "Da mesma forma que utilizamos os sentidos para filtrarmos as\n");
	fprintf(refteo, "experiências, utilizamos os sentidos para estruturar nosso\n");
	fprintf(refteo, "pensamento e nossa comunicação.\n\n");
	fprintf(refteo, "De acordo com a Programação Neurolinguísica existem os seguintes\n");
	fprintf(refteo, "sistemas representacionais.\n\n");
	fprintf(refteo, "- Auditivo\n");
	fprintf(refteo, "- Digital\n");
	fprintf(refteo, "- Cinestésico\n");
	fprintf(refteo, "- Visual\n\n");
	fprintf(refteo, "Algumas pessoas captam melhor as mensagens do mundo exterior\n");
	fprintf(refteo, "através da audição, são as pessoas chamadas auditivas.\n");
	fprintf(refteo, "Outras pessoas sentem a necessidade de perguntar muito,\n");
	fprintf(refteo, "necessitam de muitas informações e fatos. Estas são as digitais.\n");
	fprintf(refteo, "As cinestésicas aprendem melhor por meio das sensações táteis,\n");
	fprintf(refteo, "como o tato, a temperatura, a umidade, as sensações internas\n");
	fprintf(refteo, "e as emoções.\n");
	fprintf(refteo, "Já as pessoas visuais aprendem melhor quando se valendo da visão.\n\n");
	fprintf(refteo, "Cada pessoa tem um sistema representacional predominante e adequar\n");
	fprintf(refteo, "a comunicação ao sistema representacional dominante dela é fundamental\n");
	fprintf(refteo, "para diálogos eficientes.\n");
	
	fclose(refteo);
	system("REFERENCIAL_TEORICO.TXT");	
}


