#include<stdio.h>
#include<string.h>
#include<locale.h>
#include"forca.h"
#include<time.h>
#include<stdlib.h>

	char palavra[TAMANHO_PALAVRA];
	char chutes[26];
	int chutesDados = 0;
	
void abertura()
{
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}
void chuta()
{
		char chute;
		scanf(" %c",&chute);
		chutes[(chutesDados)]=chute;
		(chutesDados)++;
	
}

	void desenhaForca()
	{
		for(int i=0;i<strlen(palavra);i++)
			{
				int achou=jaChutou(palavra[i]);
					if(achou)
					{
						printf(" %c ",palavra[i]);
					}
					else
					{
						printf("_ ");	
					}
		 	
			}
			printf("\n");
	}

void adicionaPalavra()
{
	char quer;
	printf("\nVocê deseja adicionar uma nova palavra no jogo?(S/N)\n");
	scanf(" %c", &quer);
	if(quer=='S')
	{
		char novaPalavra[TAMANHO_PALAVRA];
		printf("Qual a nova palavra? ");
		scanf("%s",novaPalavra);
		FILE * f;
		f= fopen("palavra.txt","r+");
		if(f==0){
		printf("Banco de dados não disponível!\n");
		exit(1);
	}
		
		
		int qtd;
		fscanf(f,"%d",&qtd);
		qtd++;
		fseek(f,0,SEEK_SET);
		fprintf(f,"%d",qtd);
		fseek(f,0,SEEK_END);
		fprintf(f,"\n%s",novaPalavra);
		fclose(f);
	}
}

	void escolhePalavra()
	{
	FILE * f;
	f=	fopen("palavra.txt","r");
	if(f==0){
		printf("Banco de dados não disponível!\n");
		exit(1);
	}
	int qntPalavras;
	fscanf(f," %d ",&qntPalavras);
	srand(time(0));
	int randomico=rand()% qntPalavras;
	for(int i=0;i<randomico;i++)
	{
		fscanf(f,"%s",palavra);
	}
	fclose(f);
	}
	int letraexiste(char letra) {

    for(int j = 0; j < strlen(palavra); j++) {
        if(letra == palavra[j]) {
            return 1;
        }
    }

    return 0;
}
int chuteserrados() {
    int erros = 0;

    for(int i = 0; i < chutesDados; i++) {

        if(!letraexiste(chutes[i])) {
            erros++;
        }
    }

    return erros;
}
int enforcou()
{
	int erros=0;
	for(int i=0;i<chutesDados;i++)
	{
		int existe=0;
		for(int j=0;j<strlen(palavra);j++)
		{
			if(chutes[i]==palavra[j])
			{
				existe=1;
				break;
			}
		}
		if(!existe) erros++;
		 
	}
	return erros>=5;
}
	
int acertou()
{
	for(int i=0;i<strlen(palavra);i++)
	{
		if(!jaChutou(palavra[i]))
		{
			return 0;
		}
	}
	return 1;
}
int jaChutou(char letra)
{
	int achou=0;
			for(int j=0;j<chutesDados;j++)
			{
				if(chutes[j]==letra)
				{
					achou=1;
					break;
				}
			}
			return achou;
}	
void desenhaforca() {

    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavra); i++) {

        if(jaChutou(palavra[i])) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}
int main()
{
	setlocale(LC_ALL,"portuguese");


//	int acertou=0;
//	int enforcou = 0;
//	printf("%d | %d",acertou,!acertou);
	escolhePalavra();
		abertura();
	do{
	
		desenhaforca();
		
		
		chuta();
// 	chutesDados++;
        
        
        
        
	}while(!acertou()  && !enforcou());
	if(acertou()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavra);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
	adicionaPalavra();
}
