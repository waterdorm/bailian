#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MOD 1000

int Fibonacci(int n)
{
	int n1,n2,n3;
	if ( n == 0 || n == 1)
		return 1;
	else 
	{
		n1 = 1;
		n2 = 1;
		for (int i = 1; i < n; i++)
		{
			n3 = (n2 + n1)%MOD;
			n1 = n2;
			n2 = n3;

		}
		return n3;	
	}

}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int a;
	scanf("%d",&n);
	for ( int i = 0; i < n; i++ )
	{
		scanf("%d",&a);
		printf("%d\n",Fibonacci(a - 1));
	}
	return 0;
}
