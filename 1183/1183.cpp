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
//利用相等求上界，我没想到bc-ac-ab = 1（公式完全展开）,令c>=b,当c=b时，b取得上界，带入方程解出b的上界，然后枚举 
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
