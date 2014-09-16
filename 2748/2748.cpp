#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 6
int Cmp(const void *a, const void *b)
{
	return *((char *)a) - *((char *)b);
}
int main(int argc, char** argv) {
	char Input[MAX + 2];
	int sLen;

	int i,j;
	Input[0] =  127;
	scanf("%s",Input + 1);
	sLen = strlen(Input) - 1;
	qsort(Input + 1,sLen,sizeof(char),Cmp);

	for (i = 1; i <= sLen; i++)
		printf("%c",Input[i]);
	printf("\n");
	j = sLen;
	while (1)
	{
		for (j =sLen; j >= 1 && Input[j - 1] > Input[j]; j--);
		if (j >= 1)
			{
				int nMinLarger = Input[j];
				int nMinIdx = j;
				for (int k = j; k <= sLen; k++)
				{
					if (nMinLarger > Input[k] && Input[k] > Input[j - 1])
					{
						nMinLarger = Input[k];
						nMinIdx = k;
					}
				}
				Input[nMinIdx] = Input[j -1];
				Input[j - 1] = nMinLarger;
				qsort(Input + j,sLen - j + 1,sizeof(char),Cmp);
				
			}
			else break;	
			for (i = 1; i <= sLen; i++)
					printf("%c",Input[i]);
			printf("\n");
	}
	return 0;
}

