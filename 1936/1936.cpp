#include <iostream>
#include <cstdio>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char szA[100001];
	char szB[100001];
	char *p;
	int i,j,k;
	int nLenB,nLenA;
	bool mark;
	memset(szA,0,100001);
	memset(szB,0,100001);
	while (scanf("%s %s",szA,szB) != EOF)// 要注意文件结束要终止，在没有给出终止条件的情况下，否则或超时 
	{

		nLenB = strlen(szB);// 最糟糕的情况是这种情形 
		nLenA = strlen(szA);
		
		for (i = 0; i < nLenB; i++)
		{
			k = 0;
			for (j = 0; j < nLenA ; j++)
				{
					if ((p = strchr(szB + k,szA[j]))!=NULL)
							k = p - szB + 1;
					else break;
					//printf("%d ",k);
				}
			if ( nLenA == j)
			{
				printf("Yes\n");
				break;
			}
		}
		if (nLenA != j)
			printf("No\n");
		memset(szA,0,strlen(szA));
		memset(szB,0,strlen(szB));
	}
	return 0;
}
