#include <iostream>

#include <cstdio>
#include <cstdlib>
#include <cstring>
/* 深度优先，做好判断，代码真的很简洁，即使用堆栈应该也改写起来很快的吧 */

#define N 102
bool Find(char Maze[N][N],char Trace[N][N], int ha, int la, int hb, int lb)
{
	bool k;
	if ( Maze[ha][la] == '#' || Maze[ha][la] == 0 || Trace[ha][la] == 1)
		return false;
	Trace[ha][la] = 1;
	if (ha == hb && la == lb)
		return true;
	if(Find(Maze,Trace,ha+1,la,hb,lb))
		return true;
	if(Find(Maze,Trace,ha,la+1,hb,lb))
		return true;
	if(Find(Maze,Trace,ha-1,la,hb,lb))
		return true;
	if(Find(Maze,Trace,ha,la-1,hb,lb))
		return true;
	
}
int main(int argc, char** argv) {
	int k;
	int n;
	int ha,la,hb,lb;
	char Maze[N][N];
	char Trace[N][N];
	bool result;
	scanf("%d",&k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d",&n);
		memset(Maze,0,N*N);
		memset(Trace,0,N*N);
		for (int x = 1; x <= n; x++)
		{
			getchar();
			for (int y = 1; y <= n; y++)
				scanf("%c",&Maze[x][y]);
		}
		scanf("%d%d%d%d",&ha,&la,&hb,&lb);
		if ( Maze[ha+1][la+1] == '#' || Maze[hb+1][lb+1] == '#')
			{
				printf("NO\n");
				continue;
			}
		result = false;
		result = Find(Maze,Trace,ha+1,la+1,hb+1,lb+1);
		if (result)
			printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
