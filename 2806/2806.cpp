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
		for (int i = 1; i <= Alen; i++)
		{
			for (int j = 1; j <= Blen; j++)
			{
				if(cA[i-1] == cB[j-1])
					nD[i][j] = nD[i-1][j-1] + 1;
				else
					nD[i][j] = Max(nD[i-1][j],nD[i][j-1]);
			}
		}/*
		for (int i =0; i < Blen; i++)
		{
			for (int j = 0; j < Alen; j++)
			{
				cout << nD[i][j]<<' ';
			}
			cout<<endl;
		}*/
		cout<< nD[Alen][Blen]<<endl;
	}
	
	return 0;
}
