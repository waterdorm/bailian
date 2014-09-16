#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* 参考里直接进行边界判断和访问数累计，比我的简单。这里的显然效率没那么高，虽然层次明显 */
#define MAX 22
void Travel(int PosH, int PosW, char Room[][MAX], char Step[][MAX])
{
	if ( Room[PosH][PosW] == 0)
		return;
	else if ( Room[PosH][PosW] == '#')
		return;
	else if (Room[PosH][PosW] == '.')
	{
		Room[PosH][PosW] = '+';
		Step[PosH][PosW] = 1;
		Travel(PosH + 1, PosW, Room, Step);
		Travel(PosH - 1, PosW, Room, Step);
		Travel(PosH, PosW + 1, Room, Step);
		Travel(PosH, PosW - 1, Room, Step);
	}
}
int main(int argc, char** argv) {
	char Room[MAX][MAX];
	char Step[MAX][MAX];
	int W,H;
	int i,j,k;
	int PosH,PosW;
	int Count;
	while (scanf("%d%d",&W,&H) && W != 0 && H != 0)
	{
		memset(Room,0,MAX*MAX);
		memset(Step,0,MAX*MAX);
		for ( i = 1; i < H + 1; i++)
		{
			getchar();
			for ( j = 1; j < W + 1; j++)
			{
				scanf("%c",&Room[i][j]);
				if ( Room[i][j] == '@')
				{
					PosH = i;
					PosW = j;
					Room[i][j] = '.';
				}
			}
		}
		/*
		for ( i = 1; i < H + 1; i++)
		{
			printf("\n");
			for ( j = 1; j < W + 1; j++)
				printf("%c",Room[i][j]);
		}
		*/
		Travel(PosH, PosW, Room, Step);
		Count = 0;
		for ( i = 1; i < H + 1; i++)
			for ( j = 1; j < W + 1; j++)
				if ( Step[i][j] == 1)
					Count++;
		printf("%d\n",Count);
		/* 
		for ( i = 1; i < H + 1; i++)
		{
			printf("\n");
			for ( j = 1; j < W + 1; j++)
				printf("%c",Room[i][j]);
		}*/
	}
	//system("pause");
	return 0;
}
