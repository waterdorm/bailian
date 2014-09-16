#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nN[16];
	int nTemp;
	int nCount;
	int n;
	while(1)
	{
		nCount = 0;
		scanf("%d",&nTemp);
		if ( nTemp == -1) break;
		nN[0] = nTemp;
		n = 1;
		while (1)
		{	
			scanf("%d",&nTemp);
			nN[n] = nTemp;
			if ( 0 == nTemp) break;
			n++;
		}
		for (int i = 0; i < n; i++)
		{
			nTemp = nN[i];
			
			for (int j = 0; j < n; j++)
			{
				if( nN[j] == (2*nTemp)) 
				{
					nCount++;
				}
			}
				
		}
		printf("%d\n",nCount);
	}
	return 0;
}
