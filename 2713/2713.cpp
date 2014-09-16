#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nRow[1000];
	int nCases;
	int nArea = 0;
	bool State;
	scanf("%d",&nCases);
	for ( int i = 0; i < nCases; i++)
	{
		for (int j = 0; j < nCases; j++)
		{
			scanf("%d",nRow + j);
		}
		State = false;
		int k = 0;
		for (int j = 0; j < nCases; j++)
		{
			
			if (0 == nRow[j])
			{
				State = !State;
				k++;
			}
			else if (k >=2)
				break;
			else if ( 255 == nRow[j] && State == true)
			{
				nArea++;
			}

		}
		
	}
	printf("%d\n",nArea);
	return 0;
}
