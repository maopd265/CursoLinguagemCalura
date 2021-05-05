#include<stdio.h>
#include<string.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL,"portuguese");
	char palavra[20];
	sprintf(palavra,"MELANCIA");
	int acertou=0;
	int enforcou = 0;
//	printf("%d | %d",acertou,!acertou);
	
	do{
		char chute;
		scanf("%c",&chute);
		for(int i=0;i<strlen(palavra);i++)
		{
			if(palavra[i]==chute)
			{
				printf("A posição %d tem essa letra! \n",i);
			}
		}
	}while(!acertou  && !enforcou);
}
