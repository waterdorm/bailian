#include <iostream>
#include <cstdio>
#include <cstdlib>
//û�뵽 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Range(int m,int n)
{
	if (n == 1 || m == 0) return 1;
	if ( n > m ) return Range(m,m);
	return Range(m,n-1) + Range(m-n,n); 
}
int main(int argc, char** argv) {
	int t;
	int M,N;
	scanf("%d",&t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d",&M,&N);
		printf("%d\n",Range(M,N));
	}
	return 0;
}
