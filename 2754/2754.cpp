#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define LINE 8
#define NUM 92


void Queen(int Ans[][LINE], int iAns[LINE], int k, int &Count)
{
	int i,j;

	if ( k == LINE)
	{
		for ( j = 0; j < LINE; j++)
			Ans[Count][j] = iAns[j]+1;
		Count++;
		//printf("%d",Count);
		return;
	}
	for (i = 0; i < LINE; i++)
	{
		for ( j = 0; j < k; j++)
			if ( iAns[j] == i || ( j - k) == (iAns[j] - i) || ( k - j) == (iAns[j] - i)) break; 
		if ( j == k)
		{

			iAns[k] = i; // 我居然在这里把=写错了==，悲剧啊 
			Queen(Ans,iAns,k + 1,Count);
		}
	} 
}
int main(int argc, char** argv) 
{
	int Ans[NUM][LINE];
	int iAns[LINE];
	int Count = 0;
	memset(Ans,0,NUM*LINE*sizeof(int));
	memset(iAns,0,LINE*sizeof(int));
	
	Queen(Ans,iAns,0,Count);
	
//	printf("%d",Count);
	int n;
	int b;
	int i,j;
	scanf("%d",&n);
	for ( i = 0; i < n; i++)
	{
		scanf("%d",&b);
		for ( j = 0; j < LINE; j++)
			printf("%d",Ans[b - 1][j]);
		printf("\n");
	}
	return 0;
}
