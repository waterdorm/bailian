#include <iostream>
#include <cstdio>
#include <cmath> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long long a,b,c;
	
	long long j,k;
	long long min = 0x7fffffff;
	scanf("%lld",&a);
	long long i = a + (long long)sqrt((double) a*a +1);
	for (b = a + 1;b <= i;b++)
	{
		j = a*b +1;
		k = b-a;
		if(j%k ==0)
		{
			c = j/k;
			if (b+c < min)
				min = b+c;
		}

	}
	printf("%d\n",min);
	return 0;
}
//����������Ͻ磬��û�뵽bc-ac-ab = 1����ʽ��ȫչ����,��c>=b,��c=bʱ��bȡ���Ͻ磬���뷽�̽��b���Ͻ磬Ȼ��ö�� 
/*
int main(int argc, char** argv) {
	int a;
	int b,c;
	scanf("%d",&a);
	for (b = 1;;b++)
	{
		//printf("b%d\n",b);
		for(c = 1; c <= b; c++)
		{
		//	printf("c%d\n",c);
			if ((a*(b+c)) == (b*c-1))
				break;
		}
		if ((a*(b+c)) == (b*c-1))
		{
			printf("%d",b+c);
			break; 
		}
				
	}
	return 0;
}*/
