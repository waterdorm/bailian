#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nCases;
	char num[10010];
	char B[4] = {1,2,4,8};
	char A[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int temp;
	int len;
	scanf("%d",&nCases);
	for (int i = 0; i < nCases; i++)
	{
		scanf("%s",num);
		len =strlen(num);
	
		temp = 0;
		if (len%4)
		{
			for ( int j = 0; j < len%4; j++)
			{
				temp += (num[j] - '0')*B[len%4 - j - 1];
			}
				printf("%c",A[temp]);
		}
		temp = 0;	
		for ( int j = len%4; j < len; j = j + 4)//j<=len一个等号害死人啊 
		{
			temp = (num[j] - '0')*B[3];

			temp += (num[j + 1] - '0')*B[2];

			temp += (num[j + 2] - '0')*B[1];
				
			temp += (num[j + 3] - '0')*B[0];

			printf("%c",A[temp]);
		}
		printf("\n");
	}
	return 0;
}
