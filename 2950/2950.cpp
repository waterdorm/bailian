#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Data{
	int i;
	int j;
	int num;
};

bool Cmp (Data a,Data b)
{
	return (a.num > b.num);
}

int main(int argc, char** argv) {
	int T;
	
	Data D;
	Data Point;
	int time;
	int M,N,K;
	int i,j,k;
	int temp;
	int Max;
	scanf("%d",&T);
	for ( k = 0; k < T; k++)
	{
		std::vector<Data> Field;
		scanf("%d%d%d",&M,&N,&K);
		for ( i = 1; i <= M; i++)
		{

			for (j = 1; j <= N; j++)
			{
				scanf("%d",&temp);
				if (temp > 0)
				{
					D.i = i;
					D.j = j;
					D.num = temp;
					Field.push_back(D);
					// printf("%d\n",D.num);
				}
			}
	
		}
		std::sort (Field.begin(),Field.end(),Cmp);
		Point.i = 0;
		Point.j = 0;
		Point.num = 0;
		time = 0;
		while (time < K)
		{
			if (Field.empty())
					break;
			D = Field.front();
			
			if (Point.i == 0)
					Point.j = D.j;
			  // printf("%d\n",D.num);
			if (time + 1 + abs(Point.i - D.i) + abs(Point.j - D.j) + D.i<= K)
			{
				time += 1 + abs(Point.i - D.i) + abs(Point.j - D.j);
				// printf("+%d+",time);
				Point.i = D.i;
				Point.j = D.j;
				Point.num += D.num;
			}
			else break;
			Field.erase(Field.begin());
		}
		printf("%d\n",Point.num);
	}
		return 0;
	}
