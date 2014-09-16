#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// #define DEBUG
const int max = 80;
bool Find(char Board[max][max],char Step[max][max],int &Route, int Depth,int x1old,int y1old,int x1,int y1,int x2, int y2,int w,int h)
{
	bool res;
	if ( Board[x1][y1] == 1 || Step[x1][y1] == 1)
		return false;
	Step[x1][y1] = 1;
	/*
	if ( 1 < x1 && x1 < w + 2 && 1 < y1 && y1 < h + 2)
	{
		Depth++;
	}
	*/
	if ( x1 == x2 && y1 == y2)
	{
		if ( Depth < Route )
			Route = Depth;
		return true;
	}
	if ( Depth > Route)
		return true;
	if ((x1 - x1old) == 1 && (y1 - y1old) == 0)
		res = Find(Board,Step,Route,Depth,x1,y1,x1+1,y1,x2,y2,w,h);
	else 	res = Find(Board,Step,Route,Depth + 1,x1,y1,x1+1,y1,x2,y2,w,h);
	if (res) Step[x1+1][y1] = 0;
	if ((x1 - x1old) == 0 && (y1 - y1old) == 1)
		res = Find(Board,Step,Route,Depth,x1,y1,x1,y1+1,x2,y2,w,h);
	else 	res = Find(Board,Step,Route,Depth + 1,x1,y1,x1,y1+1,x2,y2,w,h);
	if (res) Step[x1][y1+1] = 0;
	if ((x1 - x1old) == -1 && (y1 - y1old) == 0)
		res = Find(Board,Step,Route,Depth,x1,y1,x1-1,y1,x2,y2,w,h);
	else 	res = Find(Board,Step,Route,Depth + 1,x1,y1,x1-1,y1,x2,y2,w,h);
	if (res) Step[x1-1][y1] = 0;
	if ((x1 - x1old) == 0 && (y1 - y1old) == -1)
		res = Find(Board,Step,Route,Depth,x1,y1,x1,y1-1,x2,y2,w,h);
	else 	res = Find(Board,Step,Route,Depth + 1,x1,y1,x1,y1-1,x2,y2,w,h);
	if (res) Step[x1][y1-1] = 0;
	Step[x1][y1] = 0;
	return true;
}
int main(int argc, char** argv) 
{
	int w,h;
	char Board[max][max];
	char Step[max][max];
	int Route;
	int BNum = 0;
	int x1,y1,x2,y2;
	while ( scanf("%d%d",&w,&h) && w != 0 && h != 0)
	{
		
		getchar();
		BNum++;
		char c = 0;
		int i,j;
		memset(Board,1,max * max);
		memset(Step,0,max * max);
		for (j = 1, i = 1; j <= w + 2; j++)
			Board[i][j] = 0;
		for (i = 2; i <= h + 1; i++)
		{
			Board[i][1] = 0;
			for (j = 2; j <= w + 2; j++) // Òª³Ôµô»Ø³µ 
			{
				c = getchar();
				if ( 'X' == c)
					Board[i][j] = 1;
				else if ( ' ' == c)
					Board[i][j] = 0;
				else if ( '\n' == c)
					break;
			}
			Board[i][j] = 0;
		}
		for (j = 1; j <= w + 2; j++)
			Board[i][j] = 0;
		#ifdef DEBUG
		for ( i= 0; i <= h + 3; i++)
		{
			for (j = 0; j <= w + 3; j++)
				printf("%d",Board[i][j]);
			printf("\n");
		}
		#endif
		int count  = 1;
		int Depth;
		printf("Board #%d:\n",BNum);
		while (scanf("%d%d%d%d",&x1,&y1,&x2,&y2) && x1 != 0 && y1 != 0 && x2 != 0 && y2 != 0)
		{
			
			Depth = 0;
			Route = max * max;
			Board[y1+1][x1+1] = 0;
			Board[y2+1][x2+1] = 0;
			Find(Board,Step,Route,Depth,y1+1,x1+1,y1+1,x1+1,y2+1,x2+1,w,h);
			if ( Route < max * max)
				printf("Pair %d: %d segments.\n",count,Route);
			else
				printf("Pair %d: impossible.\n",count);
			count++;
			Board[y1+1][x1+1] = 1;
			Board[y2+1][x2+1] = 1;
		}
		printf("\n");
	}
	
	return 0;
}
