#include <iostream>
#include <cstdio>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nCases = 4;
	int nBet[30];
	for (int i = 0;i < 26;i++)
	{
		nBet[i] = 0;
	}
	for (int i = 0; i < nCases; i++)
	{
		char c = 'A';
		while( c!= '\n')
		{
			c = getchar();
			if (c >= 'A'&& c <='Z')
				nBet[c - 'A']++;
		}
	}
	int nMax = 0;
	for (int i = 0;i < 26;i++)
	{
		if (nBet[i] > nMax)
			nMax = nBet[i];
	}
	for (int j = 0;j < nMax; j++)
	{
		for (int i = 0;i < 26; i++)
		{
			if (nBet[i] < nMax - j)
			{
				printf("  ");
			}
			else if (nBet[i] = nMax - j)
			{
				printf("* ");
				nBet[i];
				
			}
		}
		printf("\n");
	}
	for (int i = 0;i < 26;i++)
	{
		printf("%c ",'A' + i);
	}
	//system("pause");
	return 0;
}
