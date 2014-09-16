#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char cDecode(char c)
{
	if ( c >= 'A' && c <= 'E')
		return	c + 'V' - 'A';
	else if (c >= 'F' && c <= 'Z')
		 return  c - ('F' - 'A');
	else
			return c;
}
int main(int argc, char** argv) {
	char cEnd[11];
	char c;
	char cE[5];
	while(true)
	{
		scanf("%s",&cEnd);
		//printf("%d",strlen(cEnd));
		if (strlen(cEnd) == 10)
		{
		//	printf("%d",strlen(cEnd));
			break;
		}

		else 
		{
			getchar();//吃掉起始标志的回车 
			while (true)
			{
				c = getchar();
				if ( c == '\n')
					break;
				printf("%c",cDecode(c));
			}
			putchar('\n');
		}
		gets(cE);
	}
	return 0;
}
