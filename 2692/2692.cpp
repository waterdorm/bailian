#include <iostream>
#include <cstdio>
#include <cstdlib>
/* 很久没写了，以至于在scanf上犯错误，偏移地址，以及空格回车会截止。 */
int isLight(char);
int isHeavy(char);
	char a[15];
	char b[15];
	char c[15];
	
int main(int argc, char** argv) {
	int n,k;

	scanf("%d",&n);
	for ( int i = 0; i < n; i++)
	{
		scanf("%s%s%s",a,a+5,a+10);
		scanf("%s%s%s",b,b+5,b+10);
		scanf("%s%s%s",c,c+5,c+10);

		//从A开始逐个判断 
		for ( k = 0; k < 12; k++)
		{
			//当认为第K个是轻的
			if( isLight('A' + k))
			{
				printf("%c is the counterfeit coin and it is light.\n",'A'+k); 
				break;
			}
			//当认为第k个是重的 
			if( isHeavy('A' + k))
			{
				printf("%c is the counterfeit coin and it is heavy.\n",'A'+k);
				break; 
			}
		}
			
	}
	
	return 0;
}

int isLight(char N)
{
	for (int i = 0; i < 4; i++)
	{
		if ( a[i] == N)
		{ 
			if (a[10] != 'd')
			return 0;
		}
		if ( b[i] == N)
		{ 
			if (b[10] != 'd')
			return 0;
		}
		if ( c[i] == N)
		{ 
			if (c[10] != 'd')
			return 0;
		}
	}
	for (int i = 5; i < 9; i++)
	{
		if ( a[i] == N)
		{ 
			if (a[10] != 'u')
			return 0;
		}
		if ( b[i] == N)
		{ 
			if (b[10] != 'u')
			return 0;
		}
		if ( c[i] == N)
		{ 
			if (c[10] != 'u')
			return 0;
		}
	}
	return 1;
}
int isHeavy(char N)
{
	for (int i = 0; i < 4; i++)
	{
		if ( a[i] == N)
		{ 
			if (a[10] != 'u')
			return 0;
		}
		if ( b[i] == N)
		{ 
			if (b[10] != 'u')
			return 0;
		}
		if ( c[i] == N)
		{ 
			if (c[10] != 'u')
			return 0;
		}
	}
	for (int i = 5; i < 9; i++)
	{
		if ( a[i] == N)
		{ 
			if (a[10] != 'd')
			return 0;
		}
		if ( b[i] == N)
		{ 
			if (b[10] != 'd')
			return 0;
		}
		if ( c[i] == N)
		{ 
			if (c[10] != 'd')
			return 0;
		}
	}
	return 1;
}
