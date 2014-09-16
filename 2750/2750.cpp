#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,nFeet;
	scanf("%d",&n);
	while(n > 0)
	{
		scanf("%d",&nFeet);
		if (1 == (nFeet%2))
			printf("0 0\n");
		else if (0 == (nFeet % 4))
			printf("%d %d\n",nFeet / 4,nFeet / 2);
		else
			printf("%d %d\n",nFeet / 4 + 1,nFeet/2);
		n--;
	}
	return 0;
}
