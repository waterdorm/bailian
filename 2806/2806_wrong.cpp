#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Max(int a, int b)
{
	return a>b?a:b;
}
int main(int argc, char** argv) {
	char cA[200],cB[200];
	int nD[201][201];
	int Alen,Blen;
	while (scanf("%s %s",cA,cB) > 0)
	{
		memset(nD,0,sizeof(nD));
		Alen = strlen(cA);
		Blen = strlen(cB);
		for (int i =0; i < Alen; i++)
		{
			if (cB[0] == cA[i])
				nD[0][i] = 1;
			else if ( i > 0) 
				nD[0][i] = nD[0][i - 1]; 
		}
		int temp = 0;
		int nMax = 0;
		int j;
		for (int i = 1; i < Blen; i++)
		{
			for (j = temp; j < Alen; j++)
			{
				if (cB[i] == cA[j])
				{
						
						nD[i][j] = nD[i-1][j]+1;
						if (nD[i][j] > nMax)
							nMax = nD[i][j];
				}

				else if ( j > 1)
					nD[i][j] = Max(nD[i-1][j],nD[i][j-1]);
				else if ( j == 1)
					nD[i][j] = nD[i-1][j];
			}
		}
		
		for (int i =0; i < Blen; i++)
		{
			for (int j = 0; j < Alen; j++)
			{
				cout << nD[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<< nMax<<endl;
	}
	
	return 0;
}
