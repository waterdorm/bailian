#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int pall[6][6] = { {0,3,4,1,2,5},
				{1,4,0,3,2,5},
				{2,5,1,4,0,3},
				{3,0,1,4,2,5},
				{4,1,3,0,2,5},
				{5,2,1,4,0,3}};
				
int num[6][2] = {{0,1},{1,1},{2,1},{0,-1},{1,-1},{2,-1}};
char direct[6][8]={"forward","back","left","right","up","down"};
int main(int argc, char** argv) {
	int m;
	int n;
	char d[8];
	int dist;
	int tempdirect;
	int i,j,k;
	int point[3];
	int p = 0;

	scanf("%d",&m);
	for (i = 0; i < m; i++)
	{
		memset(point,0,3);
		scanf("%d",&n);
		for (j = 0; j < n; j++)
		{
			scanf("%s %d",d,&dist);
			for (k = 0; k < 6; k++)
			{	
				if (strcmp(d,direct[k]) == 0)
					break;
			}
			tempdirect = pall[p][k];
			point[num[tempdirect][0]] += point[num[tempdirect][0]] + num[tempdirect][1]*dist;
			p = tempdirect;
		// printf("%d %d %d %d\n",point[0],point[1],point[2],p);
		}
		printf("%d %d %d %d\n",point[0],point[1],point[2],p);
	}
	return 0;
}
