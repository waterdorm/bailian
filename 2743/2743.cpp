#include <iostream>
#include <cstdio>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void readstr(char *str)
{
	char c;
	int i = 0;
	while ((c = getchar()) != '\n')
		{
			if ( c >= 'A' && c <= 'Z'){
					*(str + i) = c;
					i++;}
			if ( c >= 'a' && c <= 'z'){
					*(str + i) = c - 32;
					i++;}
		}
	*(str + strlen(str)) = '\0';
	return;
}
int main(int argc, char** argv) {
	int nCases;
	char szA[101];
	char szB[101];
	char c; 
	scanf("%d",&nCases);
	getchar ();//吃掉nCases后的回车 
	int i,j,k;
	for (i = 0; i < nCases; i++)
	{
		memset (szA,0,101);// 初始化数组
		memset (szB,0,101); 
		readstr(szA);
		readstr(szB);
		if (strcmp(szA,szB))
			printf("NO\n");
		else printf("YES\n");
		getchar();
	}
	return 0;
}
