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
		printf("%x %x",start[1],end[1]);
		printf("%x %x",start,end);
		
	}
	return 0;
}
