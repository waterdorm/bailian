#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 100

	int Wood[MAX];
	int Use[MAX];
// �ο��ڵ������ǽ���ģ�����f�����е����һ���жϿ��Խ��͸��Ӷȣ�
// �������������ģ�Ҳ����ζ�Ż�ʧЧ����ʱ	
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
		if ( f(n - 1,left - Wood[i], L, N)) return true; // ʵ�������� 
		Use[i] = 0;
		if ( Wood[i] == left || left == L) break;
		// ǡ�ÿ�ʼ�ͽ�β�������㣬��Ϊ���ľ���س��֣�ֻ�û��ˡ�
		 // ��ǰ����£��޷����㵱��ľ��������������Сľ������ϵ�����¡���Ϊ��ʹ�����������������ľ�������֮�󻹻���֡� 
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
