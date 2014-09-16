#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N;
	int nCancer[102][102];
	int nArea,nGirth;
	scanf("%d",&N);
	for (int i = 0; i < 102; i++)
	{
		for (int j = 0; j < 102; j++)
			nCancer[i][j] = 99;
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
			scanf("%d",&nCancer[i][j]);
	}
	nArea = 0;
	nGirth = 0;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N +1; j++)
			if ( nCancer[i][j] <=50)
			{
				nArea++;
				if (nCancer[i-1][j] > 50||nCancer[i+1][j] > 50||nCancer[i][j-1] > 50||nCancer[i][j+1] > 50)
					nGirth++;
			}
				
			
				
	}
	printf("%d %d\n",nArea,nGirth);
	return 0;
}
