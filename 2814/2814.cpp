#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
��Ϊ��8��������������Ŷ����ģ���Ϩ���Լ��������ⶼ��ͬ��������һ��ö������⿽���Ĵ�����ĺ����������ж�������
����û�п��������������˹����������״̬�ж� 
*/
#define WIDE 3
#define HIGH 3
#define LEN WIDE*HIGH
#define STATE 4
void enumate(int Clock[],int Result[]);
bool guess(int Clock[],int Result[]);

void enumate(int Clock[],int MinResult[])
{
	int times = 1;
	bool result;
	int C;
	int Count;
	int Min = WIDE*HIGH*STATE;
	int Result[LEN] = {0};
	int i,j,m;
	for (m =0; m < WIDE + 1; m++)
	{
		times = times * STATE;
	}
	//printf("%d\n",times);
	for (m = 0; m < times; m++)
	{
		result = guess(Clock,Result);
		/*
		for ( i = 0; i < LEN; i++)
		{
			printf("%d ",Result[i]);
		}
		printf("\n");
		*/
		Count = 0;
		for ( i = 0; i < LEN; i++)
		{
			Count+=Result[i];
		}
		if ( result == true && Count < Min)
		{
			Min = Count;
			for ( j = 0; j < LEN; j++)
			{
				MinResult[j]=Result[j];
			}
			/*
			printf("\n");
			for ( i = 0; i < LEN; i++)
			{
				printf("%d ",MinResult[i]);
			}
			printf("\n");
			*/
		}
		
		Result[0]+=1;
		C = 0;
		
		while (Result[C] > 3)
		{
			Result[C] = 0;
			if( C == 2)
			{
				C = C + 5;
				Result[C] +=1;
			}
			else {
				C++;
				Result[C] +=1;
			}
			
		}
	}
}
bool guess(int Clock[],int Result[])
{
	
	Result[3] = (STATE - (Clock[0]+Result[0]+Result[1])%4)%4;
	Result[4] = (STATE - (Clock[1]+Result[0]+Result[1]+Result[2])%4)%4;
	Result[5] = (STATE - (Clock[2]+Result[1]+Result[2])%4)%4;
	Result[6] = (STATE - (Clock[3]+Result[0]+Result[3]+Result[4])%4)%4;
	Result[8] = (STATE - (Clock[4]+Result[0]+Result[2]+Result[4]+Result[6])%4)%4;
	
	if(((Clock[5]+Result[2]+Result[4]+Result[8]+Result[5])%4)%4 != 0)
	return false;
	if(((Clock[6]+Result[3]+Result[6]+Result[7])%4)%4 != 0)
	return false;
	if(((Clock[7]+Result[4]+Result[6]+Result[7]+Result[8])%4)%4 != 0)
	return false;
	if(((Clock[8]+Result[5]+Result[7]+Result[8])%4)%4 != 0)
	return false;

	return true;
	
}

int main(int argc, char** argv) 
{
	int Clock[LEN];
	int Result[LEN]={0};
	int i,j;
	for ( i = 0; i < LEN; i++)
	{
		scanf("%d",&Clock[i]);
	}
	/*
	printf("\n");
	for ( i = 0; i < LEN; i++)
	{
		printf("%d ",Clock[i]);
	}
	printf("\n");
	*/
	enumate(Clock,Result);

	for (i = 0; i < LEN; i++)
	{
		for ( j = Result[i]; j>0; j--)
		{
			printf("%d ",i + 1);
		}
	}
	return 0;
}
