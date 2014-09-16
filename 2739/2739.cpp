#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define MAX 100
#define RED 10
#define MAXX 20
void mul(const char szLine1[], const char szLine2[], char Dst[])
{
	int an1[MAX + RED];
	int an2[MAX + RED];
	int an[MAX*2 + RED];
	int i,j,k;
	memset(an1,0,sizeof(an1));
	memset(an2,0,sizeof(an2));
	memset(an,0,sizeof(an)); 
	int nLen1 = strlen(szLine1);
	j = 0;
	for (i = nLen1 - 1; i >= 0; i--)
		an1[j++] = szLine1[i] - '0';
		
	int nLen2 = strlen(szLine2);
	j = 0;
	for (i = nLen2  -1; i >= 0; i--)
		an2[j++] = szLine2[i] - '0';
	// 与加法略有不同 
	// 用选定的an1的某一位去乘an2的每一位 
	for (i  = 0; i < nLen1; i++)
		for ( j = 0; j < nLen2; j++)
			an[i + j] += an1[i]*an2[j];
	for ( i = 0; i < MAX*2; i++)
	{
		if(an[i] >= 10)
		{
			an[i+ 1] += an[i]/10;
			an[i] %= 10;
		}
	}
	j = 0; 
	for (i = MAX*2; i >= 0; i--)
		if (an[i])
		{
			j = i;
			break;
		}
	k = 0;
	for (i = j; i >= 0; i--)
	{
		sprintf(Dst+k,"%c",an[i]+'0');
		k++;
	}
	Dst[k]= '\0';
}
int compare(const char a[], const char b[])
{
	int aLen = strlen(a);
	int bLen = strlen(b);
	if (  aLen != bLen ) return aLen -bLen;
	return strcmp(a,b);
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	char a[MAX + RED];
	char b[MAX + RED];
	char an[MAX*2 + RED]; 

	int i,j;
	scanf("%d",&n);
	while ( n > 0 )
	{
		scanf("%s%s",a,b);
		getchar();
		if (compare(a,b) > 0)
		{
			printf("0\n");
			n--;
			continue;
		}
		memset(an,0,sizeof(an));
		mul("1",a,an);

		for ( i = 0; i < MAXX; i++)
		{
			mul(an,a,an);
			if(compare(an,b) < 0)
			{
				j++;
				continue;
			}
			else {
				printf("%d\n",i+1);
				break;
			}
		}
		n--;
	}
	return 0;
}

/*
		da = strtod(a,NULL);
		db = strtod(b,NULL);
		printf("%f\n",da);
		printf("%f\n",db);
		x = log10(db) / log10(da);
		printf("%f\n",log10(da));
		printf("%f\n",log10(db));
		if ( x >= 1 && x <= 20)
			printf("%.0f\n",x);
		else printf("0\n");
		//精度没办法保证，必须用大数了 
		*/
