#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += i*i*i;
	printf("%d",sum);
	return 0;
}
