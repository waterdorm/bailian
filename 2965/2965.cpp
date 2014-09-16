#include <iostream>
#include <cstdio>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char Haab[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
char Holly[20][10]= {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int main(int argc, char** argv) {
	int nCases;
	int day,year;
	int j;
	int dates;
	char month[10]; 
	scanf("%d",&nCases);
	printf("%d\n", nCases);
	for (int i = 0; i < nCases; i++)
	{
		scanf("%d.%s%d",&day,month,&year);
		
		for ( j = 0; j < 19; j++)
		{
			if (0 == strcmp(Haab[j],month))
				break;
		}
		dates = year * 365 + day + j * 20;
		printf("%d %s %d\n",1 + dates%13, Holly[dates%20], dates/260);
	}
	return 0;
}
