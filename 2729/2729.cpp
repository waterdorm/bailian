#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	long long m = 1;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		m *= i;
	}
	printf("%d",m);
	return 0;
}
