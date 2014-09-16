#include <iostream>
#include <cstdio>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void code(char a[],char b[],int nKey[],int n)
{
	int i = 0;
	for (int i =0; i < n; i++)
	{
		b[i] = ' ';
	}
	for (int i = 0; i < n; i++ )
	{
		if ('\0'==a[i])
				break;
		b[nKey[i] - 1] = a[i];
	}
	
}
int main(int argc, char** argv) {
	int nKey[202];
	char a[202];
	char b[202];
	char *p;
	char *q;
	char *temp;
	char c;
	int nLen = 0;
	int nCases = 0;
	int nIteration = 0;
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
						a[i] = '\0';
						break;
					}
					a[i] = c;
					i++;
					
				}
				p = a;
				q = b;
				for (int i = 0; i < nIteration; i++)
				{
					code(p,q,nKey,nCases);
					temp = p;
					p = q;
					q =temp;
				}
				for (int i =0; i < nCases; i++)
				{
				 	printf("%c",*(p+i));
				}
				printf("\n");
			}
			printf("\n");
	}
	return 0;
}
