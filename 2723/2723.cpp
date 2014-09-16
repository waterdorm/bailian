#include <iostream>
#include <cstdio>
#define MON 12
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char month[MON + 1] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(int argc, char** argv) {
	int week;
	
	int mon;
	scanf("%d",&week);
	int day = 13 - 1 + week - 7;
	for (int i = 0; i < MON; i++)
	{
		day = day + month[i];
		if (5 == (day%7)) 
			printf("%d\n",i+1);
	}
	return 0;
}
