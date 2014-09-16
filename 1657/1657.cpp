#include <iostream>
#include <cstdio>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nCases,i;
	scanf("%d",&nCases);
	for (i = 0;i < nCases;i++)
	{
		char start[5],end[5];
		int x,y;
		scanf("%s%s",start,end);
		x = abs(start[0]-end[0]);
		y = abs(start[1]-end[1]);
		if(0 == (x + y)) printf("%d %d %d %d\n",0,0,0,0);
		else{

			if(x < y)
				printf("%d ",y);
			else printf("%d ",x);
			if( 0 == x || 0 == y || x == y)
				printf("%d ",1);
			else printf("%d ",2);
			if( 0 == x || 0 == y)
				printf("%d ",1);
			else printf("%d ",2);
			if( (abs(x-y)%2) != 0)
				printf("Inf\n");
	
			else if( x == y)
				printf("%d\n",1);
			else 
				printf("%d\n",2);
			}
	}
	
	return 0;
}
