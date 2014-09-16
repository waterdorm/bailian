#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x,y;
	scanf("%d %d",&x,&y);
	while (1) 
	{
		if ( x == y)
		{
			printf("%d",x);
			break;
		}
		else if ( x < y)
			y = y / 2;
		else if ( x > y)
			x = x / 2;
	}

	return 0;
}

