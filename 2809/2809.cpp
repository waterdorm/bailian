#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 1000
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	char result[MAX];
	memset(result,0,sizeof(result));
	result[0] = 1;
	int m;
	int len;
	len = 1;
	for (int i = 0; i < n; ++i)
	{
		m = len;
		int temp;
		for (int j = 0; j <= m; ++j)
		{
			result[j]   *= 2;
		}
		for (int j = 0; j <= m; ++j)
		{
			result[j+1] += result[j] / 10;
			result[j]    = result[j] % 10;
		}
		for (int i = MAX - 1; ; --i)
		{
			if (result[i] != 0)
			{
				len = i;
				break;
			}
		}
		
	}
	len = 0;
	for (int i = MAX - 1; ; --i)
	{
		if (result[i] != 0)
		{
			len = i;
			break;
		}
	}
	for (int i = len; i > -1; --i)
	{
		printf("%d",result[i]);
	}
	
	return 0;
}
