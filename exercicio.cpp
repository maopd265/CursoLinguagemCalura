#include<stdio.h>
int main()
{
	int notas[5];
notas[0] = 1;
notas[1] = 4;
notas[2] = 7;
notas[3] = 5;
notas[4] = 10;
for(int i=0;i<sizeof(notas);i++)
{
	printf("\n%d ",i);
}
	return 0;
}
