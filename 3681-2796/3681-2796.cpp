#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nN;
	int nSum = 0;
	int nTemp;
	scanf("%d",&nN);
	for (int i = 0;i < 5; i++)
	{
		scanf("%d",&nTemp);
		if ( nN > nTemp)
			nSum += nTemp;
	}
	printf("%d\n",nSum);
	return 0;
}
