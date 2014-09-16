#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int sum;
	sum = 0;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		
		if ( (0 == (i%7)) || (7 == (i%10)) || (7 == (i/10))){}
		else sum = sum + (i*i);
	}
	sum = 
	printf("%d",sum);
	return 0;
}
