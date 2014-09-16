#include <iostream>
#include <cstdio>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nCases = 0;
	char cName[50];
	char cResult[50];
	int nScore = 0;
	int nGrade = 0;
	int cCadre = 0;
	int cWest = 0;
	int nArticle = 0;
	int nMaxscholar = 0;
	int temp = 0;
	int nSum = 0;
	scanf("%d",&nCases);
	for (int i = 0; i < nCases; i++)
	{
		temp = 0;
		scanf("%s %d %d %c %c %d",cName,&nScore,&nGrade,&cCadre,&cWest,&nArticle);

		if (nScore > 90)
			temp = temp +2000;
		if (nScore > 85 && cWest == 'Y')
			temp = temp +1000;
		if (nScore > 85 && nGrade > 80)
			temp = temp + 4000;
		if (nScore > 80 && nArticle >= 1)
			temp = temp + 8000;
		if (nGrade > 80&& cCadre == 'Y')
			temp =temp + 850;
		if (temp > nMaxscholar)
		{
			nMaxscholar = temp;
			sprintf(cResult,"%s",cName);
		}
		nSum = nSum +temp;
	}
	printf("%s\n%d\n%d\n",cResult,nMaxscholar,nSum);
	//system("pause");
	return 0;
}
