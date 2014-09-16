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
	scanf("%s",szLine1);
	scanf("%s",szLine2);
	int i,j;
	// 为了便于后续编程，可以将字符值重整次序放入整数数组中
	memset(an1,0,sizeof(an1));
	memset(an2,0,sizeof(an2));
	// 保存到整数数组中，同时倒序 
	int nLen = strlen(szLine1);
	j = 0;
	for (i = nLen - 1; i >= 0; i--)
		an1[j++] = szLine1[i] - '0';
		
	nLen = strlen(szLine2);
	j = 0;
	for (i = nLen  -1; i >= 0; i--)
		an2[j++] = szLine2[i] - '0';
	for (i  = 0; i < MAX; i++)
	{
		an1[i] = an1[i] + an2[i];
		if (an1[i] >= 10)
		{
			an1[i] -= 10;
			an1[i + 1]++;
		}
	}
	// 关于队首零值处理,输出时要从后往前反向输出 
	/*
	// 按原参考程序也是可以的 
	bool bStartOutput = false;
	for (i = MAX; i >= 0; i--)
	{
		if (bStartOutput)
			printf("%d",an1[i]);
		else if (an1[i])
		{
			printf("%d",an1[i]);
			bStartOutput = true;
		}
	
	}
	if (bStartOutput == false)
		printf("0");
		*/
	 
	j = 0; 
	for (i = MAX; i >= 0; i--)
		if (an1[i])
		{
			j = i;
			break;
		}

	for (i = j; i >= 0; i--)
		printf("%d",an1[i]);
		
	// 果然要处理0+0这种特殊情况 

	return 0;
}
