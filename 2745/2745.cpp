#include <iostream>
#include <cstdio>
#include <cstring> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// �ֱʻ�����������Ͳ������ˣ���˵�ҿ��ܻ��о���ģ�µ��󣬺Ǻ� 
int main(int argc, char** argv) {
	int s;
	char n[10];
	char n1[11] = {"- -- -----"};// 0, 2, 3, 5, 6, 7, 8, 9
	char n2[11] = {"|   ||| ||"};// 0, 4, 5, 6, 8, 9
	char n3[11] = {"|||||  |||"};// 0, 1, 2,3, 4, 7, 8, 9
	char n4[11] = {"  ----- --"};// 2, 3, 4, 5, 6, 8, 9
	char n5[11] = {"| |   | | "};// 0, 2, 6, 8
	char n6[11] = {"|| |||||||"};// 0, 1, 3, 4, 5, 6, 7, 8, 9
	char n7[11] = {"- -- -- --"};// 0, 2, 3, 5, 6, 8, 9
	
	int strLen,nNum;
	int i,j,k;
	while (scanf("%d %s",&s,n) && s != 0)
	{
		strLen  = strlen(n);
		for (i = 0; i < strLen; i++) // �����һ�� 
		{
			nNum = n[i] - '0';
			printf(" ");
			for (j = 0; j < s; j++)
				printf("%c",n1[nNum]);
			printf(" ");
			if (i != strLen)
				printf(" ");
		}
		printf("\n");
		for (i = 0; i < s; i++)// ��������� 
		{
			for (j = 0; j < strLen; j++)
			{
				nNum = n[j] - '0';
				printf("%c",n2[nNum]);
				for (k = 0; k < s ; k++)
					printf(" ");
				printf("%c",n3[nNum]);
				if (j != strLen)
				printf(" ");					
			}
			printf("\n");
		}
		for (i = 0; i < strLen; i++) // ������Ļ� 
		{
			nNum = n[i] - '0';
			printf(" ");
			for (j = 0; j < s; j++)
				printf("%c",n4[nNum]);
			printf(" ");
			if (i != strLen)
				printf(" ");
		}
		printf("\n");
		for (i = 0; i < s; i++)// ��������� 
		{
			for (j = 0; j < strLen; j++)
			{
				nNum = n[j] - '0';
				printf("%c",n5[nNum]);
				for (k = 0; k < s ; k++)
					printf(" ");
				printf("%c",n6[nNum]);	
				if (j != strLen)
				printf(" ");				
			}
			printf("\n");
		}
		for (i = 0; i < strLen; i++) // ������߻� 
		{
			nNum = n[i] - '0';
			printf(" ");
			for (j = 0; j < s; j++)
				printf("%c",n7[nNum]);
			if (i != strLen)
				printf(" ");
			printf(" ");
		}
		printf("\n");
		printf("\n");
	}
	return 0;
}
