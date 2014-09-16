#include <iostream>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

#define M 55
#define N 55
using namespace std;
/*  直接用引用修改数据，可以参看2815-.cpp */
struct Room{
	int wall;
	int step;
};
int CountRoom(Room Castle[M][N], int x, int y)
{

	if ( Castle[x][y].step == 1)
		return 0;
	int k = 1;
	Castle[x][y].step = 1;
			// printf("%d\n",data.step);
	int wall = Castle[x][y].wall;
		// printf("%d\n",wall);
		if ( !(wall & 0x8))
		k+=CountRoom(Castle,x+1,y);
		if ( !(wall & 0x4))
		k+=CountRoom(Castle,x,y+1);
		if ( !(wall & 0x2))
		k+=CountRoom(Castle,x-1,y);
		if ( !(wall & 0x1))
		k+=CountRoom(Castle,x,y-1);	
	return k;
	
}
int main(int argc, char** argv) {
	Room Castle[M][N];

	int w,h;
	scanf("%d%d",&w,&h);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			Castle[i][j].wall = 0;
			Castle[i][j].step = 0;
		}
		
	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= h; j++)
			scanf("%d",&Castle[i][j].wall);
	/* for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			printf("%d ",Castle[i][j].wall);*/
	int step;
	int count = 0;
	int max = 0;
	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= h; j++)
		{
			if (Castle[i][j].step == 0)
			{
				step = 0;
				step = CountRoom(Castle,i,j);
				count++;
				// printf("%d\n",data.step);
				if (step > 0)
				{

					if(step > max)
						max = step;
				}
			}
		}


	printf("%d\n",count);
	printf("%d\n",max);
	return 0;
}
