#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 100

	int Wood[MAX];
	int Use[MAX];
// 参考内的排序是降序的，所以f函数中的最后一个判断可以降低复杂度，
// 但我起初是升序的，也就意味优化失效，超时	
int compare(const void *a, const void * b)
{
	return -(*(int *)a - *(int*)b);
}
bool f(int n, int left, int L, int N)
{
	int i,j;
	if ( n == 0 && left == 0) return true;
	if (left == 0) left = L;
	for ( i = 0; i < N; i++)
	{
		if (Use[i] == 1) continue;
		if (Wood[i] > left) continue;
		Use[i] = 1;
		if ( f(n - 1,left - Wood[i], L, N)) return true; // 实现逐层回退 
		Use[i] = 0;
		if ( Wood[i] == left || left == L) break;
		// 恰好开始和结尾都不满足，因为这个木棒必出现，只好回退。
		 // 当前情况下，无法满足当该木棒出现在其他更小木棒的组合的情况下。因为即使现在跳过，包含这个木棒的组合之后还会出现。 
	}
	return false;
}
int main(int argc, char** argv) {

	int n;
	int i,j;
	int M;
	int p;
	int N;
	bool Result;
	while ( scanf("%d",&n) && n != 0)
	{
		M = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d",&Wood[i]);
			M += Wood[i]; 
		}
		qsort(Wood,n,sizeof(int),compare);
		p = Wood[0];
		//printf("%d",p);
		Result = false;
		memset(Use,0,MAX*sizeof(int));
		for ( i = p; i <= M; i++)
		{
			if ( M % i == 0)
			{
				if (f(n,i,i,n))
				{
					printf("%d\n",i);
					break;
				}

			}else continue;

		} 
	}
	return 0;
}
