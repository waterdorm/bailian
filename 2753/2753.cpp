#include <iostream>
#include <cstdio>
#include <cstdlib>
int Fibonacci(int n)
{
	if ( n == 0 || n == 1)
		return 1;
	else 
	{
		n = Fibonacci( n - 1) + Fibonacci( n - 2);
		return n;	
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
