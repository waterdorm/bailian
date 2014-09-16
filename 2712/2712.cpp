#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	long data[6];
	int nCases;
	int day = 0;
	scanf("%d",&nCases);
	int i,j,k;
	for (i = 0; i < nCases; i++)
	{
		day = 0;
		scanf("%ld%ld%ld%ld%ld",&data[0],&data[1],&data[2],&data[3],&data[4]);
		if ( data[0] == data[3])
		{
			day = data[4] - data[1];
		}
		else {
			for ( j = data[0] - 1; j < data[3] - 1; j++)
				day += month[j];
			day = day - data[1] + data[4]; // 不包括结束那一天 
		}
		for (j = 0; j < day ; j++)
				data[2] = data[2]*2;
		printf("%d\n",data[2]);
	}
	return 0;
}
