#include <iostream>
#include <cstdio>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 101
int isPerFectCube(int a,int b,int c,int d)
{
	int Temp;
	Temp = b*b*b + c*c*c + d*d*d;
	if( (a*a*a) == Temp)
		return 1;
	return 0;
}
int main(int argc, char** argv) {
	
	int a,b,c,d;
	int N;
	int Ta,Tb,Tc,Td;
	scanf("%d",&N);
	for(a = 2; a <= N; a++)
	{
		for(b = 2; b <= N; b++)
		{
			for(c = b; c <= N; c++)
			{
				for(d = c; d <= N; d++)
				{
					if(isPerFectCube(a,b,c,d))
					printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
				}
			}
		}
	}
	
	return 0;
}
/*������Ϊbcd���ֵĴ���ͬ���ظ���������������ǰ����N�ڵ�����ȷʵ���Լ���*/
