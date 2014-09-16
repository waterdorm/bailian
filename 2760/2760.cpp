#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
// #define DEBUG
/* ����һ�����˵Ĺ��̣������һ����˵���һ�� */
const int nMax = 110;
int nT[nMax][nMax];
int nD[nMax][nMax];
int main(int argc, char** argv) {
	int nN;
	int nL,nR;
	scanf("%d",&nN);
	memset(nT,0,sizeof(nT));
	memset(nD,0,sizeof(nD));
	for (int i = 0; i < nN; i++)
		for (int j = 0; j <= i; j++)
		scanf("%d",&nT[i][j]);
	
	for ( int i = nN - 1; i >= 0; i--)
	{
		for ( int j = i; j >= 0; j--)
		{
			nL = nD[i + 1][j] + nT[i][j];
			nR = nD[i + 1][j + 1] + nT[i][j];
			if ( nL > nR )
				nD[i][j] = nL;
			else nD[i][j] = nR;
		}
	}
	printf("%d\n",nD[0][0]);
	#ifdef DEBUG
	for (int i = 0; i < nN; i++)
	{
		printf("\n");
		for (int j = 0; j <= i; j++)
		printf(" %d",nT[i][j]);
	}
	#endif
	return 0;
}
