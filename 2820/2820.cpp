#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define LEN 26
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp (const void *a,const void *b)
{
	if ( *(char*)a < *(char*)b ) return 1;
	if ( *(char*)a == *(char*)b ) return 0;
	if ( *(char*)a > *(char*)b ) return -1;
}
int main(int argc, char** argv) {
	char szA[LEN];
	char szB[LEN];
	char c;
	int i,j,k;
	memset(szA,0,LEN);
	memset(szB,0,LEN);
	while ((c = getchar()) && c != '\n')// c = getchar() 不加括号的话，会有优先级的问题 
	{
		szA[c - 'A']++;
	//	printf("%c ",c);
	}
	while ((c = getchar()) && c != '\n')
	{
		szB[c - 'A']++;
	//	printf("%c ",c);
	}
	qsort (szA, LEN,sizeof(char),cmp);
	qsort (szB, LEN,sizeof(char),cmp);
	for (i = 0; i < LEN; i++)
	{
		//printf("%d %d",szA[i] ,szB[i]);
		if (szA[i] != szB[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
