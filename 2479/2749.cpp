#include <iostream>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

/* 逻辑没错的话，很快就能解出来了 */
int Count(int a, int an)
{
	int k = 0;
	// printf("%d*",an);
	if ( a == 1)
		return 1;
 	for (int i = an; i <= a; i++)
		if ( a % i == 0)
			k+=Count(a/i,i);
	return k;		
}
int main(int argc, char** argv) {
	int n;
	int a;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a);
		printf("%d\n",Count(a,2));
	}
	
	return 0;
}
