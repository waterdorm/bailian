#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 200

int main(int argc, char** argv) {
	char szLine1[MAX + 10];
	char szLine2[MAX + 10];
	int an1[MAX + 10];
	int an2[MAX + 10];
	int an[2*MAX + 10];
	scanf("%s",szLine1);
	scanf("%s",szLine2);
	int i,j;
	// Ϊ�˱��ں�����̣����Խ��ַ�ֵ���������������������
	memset(an1,0,sizeof(an1));
	memset(an2,0,sizeof(an2));
	memset(an,0,sizeof(an)); 
	// ���浽���������У�ͬʱ���� 
	int nLen1 = strlen(szLine1);
	j = 0;
	for (i = nLen1 - 1; i >= 0; i--)
		an1[j++] = szLine1[i] - '0';
		
	int nLen2 = strlen(szLine2);
	j = 0;
	for (i = nLen2  -1; i >= 0; i--)
		an2[j++] = szLine2[i] - '0';
	// ��ӷ����в�ͬ 
	// ��ѡ����an1��ĳһλȥ��an2��ÿһλ 
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

	for (i = j; i >= 0; i--)
		printf("%d",an[i]);
	return 0;
}
		
