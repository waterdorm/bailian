#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAX 1024
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Cmp(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}
int main(int argc, char** argv) {
	int mCases;
	int n,k;
	int num[MAX + 10];
	int i,j,l;
	scanf("%d",&mCases);
	for (i = 0; i < mCases; i++)
	{
		scanf("%d%d",&n,&k);
		num[0] = MAX + 10;
		for (j = 1; j <= n; j++)
			scanf("%d",num + j);
		for ( j = 0; j < k; j++)
		{
			for (l = n; l >=1 && num[l-1] > num[l]; l--); // 以后不要用单个l很容易和1分不清的。 
			// 找到第一个满足 num[l-1] < num[l] 的l 
				if (l >= 1)
				{
					int nMinLarge = num[l];
					int nMinIdx = l;
					// 在L和n，找到比num[l-1]大，但最小的那个。 
					for (int kk = l; kk <= n; kk++)
					{
						if (nMinLarge > num[kk] && num[kk] > num[l-1])
						{
							nMinLarge = num[kk];
							nMinIdx = kk;
						}
					}
					// 交换 比num[l-1]大，但最小的那个，和num[j -1] 交换 
						num[nMinIdx] = num[l -1];
						num[l-1] = nMinLarge;
					// 排序 L 到 n间的数据，升序排列 
						qsort(num + l,n-l+1,sizeof(int),Cmp);
				}
				else{
					for (l = 1; l <= n; l++)
						num [l] = l;
				}

		}
		for ( j = 1; j <= n; j++)
			printf("%d ",num[j]);
			printf("\n");
	}
	return 0;
}
