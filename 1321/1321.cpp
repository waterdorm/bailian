#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
const int max = 64;
int count;
struct node{
	int x;
	int y;
};
node Chess[max];
node Path[max];
int Mark[max];
int Put(int k, int num, int m,int start)
{
	int i,j;
	if ( k  == m)
	{
		count++;
	}
	for (i = start; i < num; i++)
	{
		if ( Mark[i] == 1)
			continue;
		for (j = 0; j < m; j++)
		{
			if (Path[j].x == Chess[i].x || Path[j].y == Chess[i].y)
				break;
		}
		if ( j == m)
		{
			Path[m].x = Chess[i].x;
			Path[m].y = Chess[i].y;
			Mark[i] = 1;
			Put(k,num,m + 1,i);
			Mark[i] = 0;
			//Path[m].x = 0;
			//Path[m].y = 0;
		}
	}
}
int fun(int k)
{
	if ( k == 1)
		return k;
	return k * fun( k - 1);
}
int main(int argc, char** argv) 
{
	int n,k;
	char c;
	int num;
	while ( scanf("%d%d",&n,&k) && n!= -1 && k != -1)
	{
		num = 0;
		memset(Chess,0,sizeof(Chess));
		memset(Path,0,sizeof(Path));
		memset(Mark,0,sizeof(Mark));
		for (int i = 0; i < n; i++)
		{
			getchar();
			for (int j = 0; j < n; j++)
			{
				c=getchar();
				if ( '#' == c)
				{
					Chess[num].x = i;
					Chess[num].y = j;
					num++;
				}
			}
		
		}
		count = 0;
		Put(k,num,0,0);
		//count = count/ fun(k);
		printf("%d\n",count);
		/*
		for (int i = 0; i < num; i++)
		{
			printf("%d %d",Chess[i].x,Chess[i].y);
			printf("\n");
		
		}*/

	}
	return 0;
}

