#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 200
char szLine1[MAX + 10];
char szLine2[MAX + 10];
int an1[MAX + 10];
int an2[MAX + 10];
int aResult[MAX + 10];
int Substract (int *p1,int *p2,int nLen1,int nLen2)
{
	int i;
	if (nLen1 < nLen2)
		return -1;
	bool bLarger = false;
	if (nLen1 == nLen2)
	{
		for ( i = nLen1 -1; i >= 0; i--) 
		{
			if (p1[i] > p2[i])
				bLarger = true;
			else if (p1[i] < p2[i])
			{
				// 某位除数大于被除数，被处死的恶高位又没有比除数大的
				// 所以被除数小于除数 
				if (!bLarger)
					return -1;
			}
		}
		 
	}
	for ( i = 0; i < nLen1; i++)
	{
		p1[i] -= p2[i];
		if (p1[i] < 0)
		{
			p1[i] += 10;
			p1[i+1]--;
		}
	}
	for (i = nLen1 - 1; i >= 0; i--)
		if (p1[i])
			return i + 1;
	return 0; 
} 
int main(int argc, char** argv) {
	int t,n;
	char szBlank[20];
	scanf("%d",&n);
	for ( t= 0; t < n; t++)
	{
		scanf("%s",szLine1);
		scanf("%s",szLine2);
		int i,j;
		memset(an1,0,sizeof(an1));
		memset(an2,0,sizeof(an2));
		memset(aResult,0,sizeof(aResult));
		
		int nLen1 = strlen(szLine1);
		int nLen2 = strlen(szLine2);
		// 如果被除数长度小于除数，就可以进行下一个了。不会以0开始 

		j = 0;
		for (i = nLen1 - 1; i >= 0; i--)
			an1[j++] = szLine1[i] - '0';
		j = 0;
		for (i = nLen2  -1; i >= 0; i--)
			an2[j++] = szLine2[i] - '0';
		if (nLen1 < nLen2)
		{
			printf("0\n");
			continue;
		}
		nLen1  = Substract(an1,an2,nLen1,nLen2); 
		if (nLen1 < 0)
		{
			printf("0\n");
			continue;
		}
		else if (nLen1 == 0)
		{
			printf("1\n");
			continue;
		}
		// 首次，未进位减法。记录 
		aResult[0] ++;
		int nTimes = nLen1 - nLen2;
		if (nTimes < 0)
			goto OutputResult;
		else if ( nTimes > 0)
		{
			// 对an2，乘以10的某次幂 
			for ( i = nLen1 - 1; i >= 0;i--)
			{
				if (i >= nTimes)
					an2[i] = an2[i - nTimes];
				else an2[i] = 0;
			} 

		}
		// 从较大的开始减，避免商某位过大 
		nLen2 = nLen1;
		for ( j = 0; j <= nTimes; j++)
		{
			int nTmp;
			while ((nTmp = Substract(an1,an2 + j,nLen1,nLen2 - j)) >= 0)
			{
				nLen1=nTmp;
				aResult[nTimes-j]++;
			}
		}
		OutputResult: 
		for (i = 0; i < MAX; i++)
		{
			if( aResult[i] >= 10)
			{ 
				aResult[i+1] += aResult[i] /10;
				aResult[i] %= 10;
			} 
		}
		bool bStartOutput = false;
		for (i = MAX; i>=0;i--)
		{
			if (bStartOutput)
				printf("%d",aResult[i]);
			else if (aResult[i])
			{
				printf("%d",aResult[i]);
				bStartOutput = true;
			}
		}
		if (!bStartOutput)
			printf("0\n");
		printf("\n");
	}
	return 0;
}
