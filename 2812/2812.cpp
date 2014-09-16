#include <iostream>
#include <cstdio>
#include <cstdlib>
struct PLANT{
	int x;
	int y;
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int mycompare(const void *p1, const void *p2)
{
	PLANT * a, *b;
	a = (PLANT *) p1;
	b = (PLANT *) p2;
	if (a->x == b->x ) 
		return( a->y - b->y );
	return ( a->x - b->x );
}
int main(int argc, char** argv) {
	int R,C;
	int Count;
	int MaxCount = 2;
	int N;
	PLANT plants[5001];
	PLANT front,back;
	int xstep;
	int ystep;
	int px,py;
	int i,j,k;
	scanf("%d%d",&R,&C);
	scanf("%d",&N);
	for ( i = 0; i < N; i++)
		scanf("%d %d",&plants[i].x,&plants[i].y);
	qsort(plants,N,sizeof(PLANT),mycompare);
/*	for ( i = 0; i < N; i++)
		printf("%d %d\n",plants[i].x,plants[i].y);*/
	for(i = 0; i < N - 2; i++)
	{
		for (j = i + 1; j < N - 1; j++)
		{
			Count = 2;
			xstep = plants[j].x - plants[i].x;
			ystep = plants[j].y - plants[i].y;
			//front.x = plants[i].x;
			//front.y = plants[i].y;
			back.x  = plants[j].x;
			back.y  = plants[j].y;
			
			px = plants[i].x - xstep;
			py = plants[i].y - ystep;
			if ( px <= R && px >=1 && py <=C && py >= 1)
				continue;
			if(plants[i].x + MaxCount*xstep > R)
				break;
			if(plants[i].y + MaxCount*ystep > C)
				continue;
			back.x  = back.x + xstep;
			back.y  = back.y + ystep;
			for (k = 1; k <= N; k++)
			{
   				if ( back.x <= R && back.y <= C && back.x >=1 && back.y >=1)
   				{
   					if (bsearch(&back,plants,N,sizeof(PLANT),mycompare))
   					{
   						back.x  = back.x + xstep;
						back.y  = back.y + ystep;
						Count++;
   					}

					else 
					{	
						Count = 0;
						break;
					}
   				}
				

			}

			if (Count > MaxCount)
				MaxCount = Count;
		}
	}
	if ( MaxCount >= 3)
		printf("%d\n",MaxCount);
	else 
		printf("0\n");
	return 0;
}
/*			
				*/
