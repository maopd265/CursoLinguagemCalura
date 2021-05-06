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
int main()
{
	setlocale(LC_ALL,"portuguese");


//	int acertou=0;
//	int enforcou = 0;
//	printf("%d | %d",acertou,!acertou);
	escolhePalavra();
		abertura();
	do{
	
		desenhaForca();
		
		
		chuta();
// 	chutesDados++;
        
        
        
        
	}while(!acertou()  && !enforcou());
	adicionaPalavra();
}
