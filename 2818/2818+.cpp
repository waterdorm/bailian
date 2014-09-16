#include <iostream>
#include <cstdio>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int nKey[202];
	char a[202];
	char b[202];
	int nMax[202];
	
	int n;
	char c;
	int nLen = 0;
	int nCases = 0;
	int nIteration = 0;
	int max;
	while(true)
	{
			scanf("%d",&nCases);
			if (0 == nCases)
				break;
			for (int i = 0; i < nCases; i++)
			{
				scanf("%d",&nKey[i]);
			}
			while(true)
			{
				nLen = 0;
				scanf("%d",&nIteration);
				if (0 == nIteration)
					break;
				getchar();
				int i = 0;
				while (true)
				{
					
					c = getchar();
					if ('\n'==c)
					{
						a[i] = ' ';
						break;
					}
					a[i] = c;
					i++;
				//	printf("%c",a[i]);
				}
				
				for (int i = 0; i < nCases; i++)
				{
					max = i + 1;
					b[i] = ' ';
					for (int j = 0;; j++)
					{
						max = nKey[max -1];
						if ( i + 1== max)
						{
							nMax[i] = j + 1;
							break;
						}
					}
					//printf("%d ",nMax[i]);
				}
				
			//	printf("\n");
				for (int i = 0; i < nCases; i++)
				{
					n = nIteration%nMax[i];
					int j;
					int temp = i + 1;
					//printf("%d ",n);
					for (j = 0; j < n; j++)
					{
						temp = nKey[temp - 1];
					}
					b[temp - 1] = a[i];
					a[i] = ' ';
				}
				
				for (int i =0; i < nCases; i++)
				{
				 	printf("%c",b[i]);
				}
				printf("\n");
			}
			printf("\n");
	}
	return 0;
}
