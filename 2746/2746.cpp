#include <iostream>
#include <bitset>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m,n;
	int temp;
	int i,j,k;
	std::bitset<301> ls;
	while (scanf("%d%d",&n,&m) && ((m + n)!= 0))
	{


		ls.reset();
		temp  = -1;
		for (j = 0; j < n - 1; j++)
		{
			//printf("Run\n");
			for (i = 0; i < m;)
			{
				temp = (temp + 1)%n;
				if (ls.test(temp) == true) continue;
				else i++;
				
			}
			//printf("%d+",temp);
			ls.set(temp);
		}
		for (j = 0; j < n ; j++)
		{
			if (ls.test(j) == false)
				printf("%d\n",j + 1);
		}
		
	}
	return 0;
}
