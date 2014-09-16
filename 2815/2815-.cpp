#include <iostream>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

#define M 52
#define N 52
using namespace std;
/* ֱ���������޸����ݣ������Ƿ���ֵ��ȻҲ�ǿ��Ե� */
struct Room{
	int wall;
	int step;
};
void CountRoom(Room Castle[M][N], Room &data, int x, int y)
{

	if ( Castle[x][y].step == 1 )// ��wall==0ʱ�ǿ��Եģ���ʾû��ǽ����������һ�������жϵ��½���� 
		return;
	if ( Castle[x][y].step == 0)
	{
		data.step++;
		Castle[x][y].step = 1;
	}
			// printf("%d\n",data.step);
		int wall = Castle[x][y].wall;
		// printf("%d\n",wall);
		if ( !(wall & 0x8))
		CountRoom(Castle,data,x+1,y);
		if ( !(wall & 0x4))
		CountRoom(Castle,data,x,y+1);
		if ( !(wall & 0x2))
		CountRoom(Castle,data,x-1,y);
		if ( !(wall & 0x1))
		CountRoom(Castle,data,x,y-1);	


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
	Room data;
	data.step = 0;
	data.wall = 0;
	int count = 0;
	int max = 0;
	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= h; j++)
		{
			if (Castle[i][j].step == 0)
			{
				data.step = 0;
				CountRoom(Castle,data,i,j);
				count++;
				// printf("%d\n",data.step);
				if (data.step > 0)
				{

					if(data.step > max)
						max = data.step;
				}
			}
		}


	printf("%d\n",count);
	printf("%d\n",max);
	return 0;
}
