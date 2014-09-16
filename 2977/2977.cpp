#include <iostream>
#include <cstdio>
#include <cstdlib>
#define STRENGTH 23
#define EMOTION 28
#define INTELLIGENCE 33
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int p,e,i,d;
	int t;
	int j;
	int times = 0;
	while (1)
	{
		scanf("%d %d %d %d",&p,&e,&i,&d);
		if ( p == -1 && e == -1 && i == -1 && d == -1)
			break;
			
		times++;
		for(j=d+1; j<21252; j++)
		 if ((j-p)%23 == 0) break;
	 	for( ; j<21252; j=j+23)
 			if ((j-e)%28 == 0) break;
	 	for( ; j<21252; j=j+23*28)
 			if ((j-i)%33 == 0) break;
			printf("Case %d: the next triple peak occurs in %d days.\n",times,j - d);
	}

	return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define STRENGTH 23
#define EMOTION 28
#define INTELLIGENCE 33
//这个虽然效率低，但是没错的。可能因为最后没找到的数值，因为加值方式不同而输出不同，但是显然是对的 

int main(int argc, char** argv) {
	int p,e,i,d;
	int t;
	int j;
	int times = 0;
	while (1)
	{
		scanf("%d %d %d %d",&p,&e,&i,&d);
		if ( p == -1 && e == -1 && i == -1 && d == -1)
			break;
			
		times++;
		for (j = d + 1; j < 21253; j++)
		{
			t = j;
			if( ((t - p) % STRENGTH == 0) && ((t - e) % EMOTION == 0) && ((t - i) % INTELLIGENCE == 0))
			{
				printf("Case %d: the next triple peak occurs in %d days.\n",times,j - d);
				break;
			}
		}

	}
	return 0;
}
*/
