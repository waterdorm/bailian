#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int nCases = 0;
	std::string cGender;
	int nCount = 0;
	float fTemp = 0;
	scanf("%d",&nCases);
	for (int i = 0; i < nCases; i++)
	{
		nCount = 0;
		std::cin>>cGender;
		//std::cout<<cGender.size()<<std::endl;
		scanf("%f",&fTemp);
		if (fTemp < 4.0 || fTemp > 10.0)
			nCount++;
		scanf("%f",&fTemp);
		if (fTemp < 3.5 || fTemp > 5.5)
			nCount++;
		scanf("%f",&fTemp);
		if (6 == cGender.size() && (fTemp < 110 || fTemp > 150))
			nCount++;
		if (4 == cGender.size() && (fTemp < 120 || fTemp > 160))
			nCount++;
		scanf("%f",&fTemp);
		if (6 == cGender.size() && (fTemp < 36 || fTemp > 40))
			nCount++;
		if (4 == cGender.size() && (fTemp < 42 || fTemp > 48))
			nCount++;
		scanf("%f",&fTemp);
		if (fTemp < 100 || fTemp > 300)
			nCount++;		
		if (0 == nCount)
			printf("normal\n");
		else
			printf("%d\n",nCount);	
	}
	return 0;
}
