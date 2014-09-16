#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Initialize(char A[],int n)
{
	for (int i = 0; i < n; i++)
	{
		A[i] = 0;
	}
}
int FindMax(char A[],int n)
{
	int nMax = 0;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		//printf("%d",A[i]);
		if (A[i] > nMax)
		{
				nMax = A[i];
				index = i;
		}

	}
	//printf("%d",nMax);
	return index;
}
int main(int argc, char** argv) {
	int nCases = 0;
	char szAlphabet[26];
	char cTemp;
	int nTemp = 0;
	int i;
	scanf("%d",&nCases);
	getchar();
	for (i = 0; i < nCases; i++)
	{
		Initialize(szAlphabet,26);
		while ((cTemp = getchar())&& cTemp != '\n')
		{
			szAlphabet[cTemp - 'a']++;
			//printf("%c ",cTemp);
		}
		if (i != nCases - 1)
			getchar();
		nTemp = FindMax(szAlphabet,26);
		printf("%c %d\n",nTemp + 'a',szAlphabet[nTemp]);
	}
	return 0;
}
