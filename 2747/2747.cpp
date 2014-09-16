#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,t;
	int a1,a2,a3;
	int Max;
	scanf("%d",&t);
	while ( t > 0 )
	{
		scanf("%d",&n);
		Max = 0;
		for (a1= 0; a1 <= n; a1++)
		{
			for (a2 = 0; a2 <= n; a2++)
			{
				if ( (a1 + a2)%2 != 0)
					continue;
				for (a3 = 0; a3 <= n; a3++)
				{
					if ( (a2 + a3) %3 != 0)
						continue;
					else if ( (a1 + a2 + a3)%5 != 0)
							continue;
					if ( a1 + a2 + a3 > Max)
					{
						Max = a1 + a2 + a3;
					}
					
						
				}
			} 
		}
		printf("%d\n",Max);
		t--;
	}
	return 0;
}
