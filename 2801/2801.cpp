#include <iostream>
#include <cstdio>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nAlphabet[26] = {0};
	char nTemp[110];
	char nBegin = 'A';
	int nN,nM,nP;
	scanf("%d%d%d",&nN,&nM,&nP);
	for (int i = 0; i < nN; i++)
	{
		scanf("%s",nTemp);
		for (int j = 0;  j< nM; j++)
			nAlphabet[nTemp[j] - nBegin] = nAlphabet[nTemp[j] - nBegin] + 1;
	}
	for (int i = 0; i < nP; i++)
	{
		scanf("%s",nTemp);
		for (int j = 0;  nTemp[j] != '\0'; j++)//P的宽度没有说明，因为这个原因我多提交了两次 
			nAlphabet[nTemp[j] - nBegin] = nAlphabet[nTemp[j] - nBegin] - 1;
	}
	for (int i = 0; i < 26; i++)
	{
		
		for(int j = 0; j < nAlphabet[i]; j++)
			printf("%c",nBegin + i);
	}
	printf("\n");
	return 0;
}
