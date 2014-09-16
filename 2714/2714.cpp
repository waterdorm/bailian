#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nCases;
	int nTemp;
	double nAge  = 0;
	scanf("%d",&nCases);
	for ( int i = 0; i < nCases; i++)
	{
		scanf("%d",&nTemp);
		nAge = nAge + nTemp;
	}
	printf("%.2f",nAge/nCases);
	return 0;
}
