#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nN;
	int Depth;
	char cTemp;
	int nPoint[1002];
	while (scanf("%d",&nN) > 0)
	{
		getchar();
		int j = 0;
		for (int i = 0; i < nN; i++)
		{
			cTemp = getchar();
			// printf("%c ",cTemp);
			if (cTemp == '1')
			{
				nPoint[j] = i+1;
				j++;
			}
			else{
				j--;
				printf("%d ", nPoint[j]);
			}
				
		}
		getchar();
		putchar('\n');
	}
	return 0;
}
