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
			for (l = n; l >=1 && num[l-1] > num[l]; l--); // �Ժ�Ҫ�õ���l�����׺�1�ֲ���ġ� 
			// �ҵ���һ������ num[l-1] < num[l] ��l 
				if (l >= 1)
				{
					int nMinLarge = num[l];
					int nMinIdx = l;
					// ��L��n���ҵ���num[l-1]�󣬵���С���Ǹ��� 
					for (int kk = l; kk <= n; kk++)
					{
						if (nMinLarge > num[kk] && num[kk] > num[l-1])
						{
							nMinLarge = num[kk];
							nMinIdx = kk;
						}
					}
					// ���� ��num[l-1]�󣬵���С���Ǹ�����num[j -1] ���� 
						num[nMinIdx] = num[l -1];
						num[l-1] = nMinLarge;
					// ���� L �� n������ݣ��������� 
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
