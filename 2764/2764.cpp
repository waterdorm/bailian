#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char num[1010];
	int n;
	char c;
	int len;
	int i,j;
	while(1)
	{
		scanf("%s",num);
		if (num[0] == '0')
			break;
		
		while (1)
		{
			n = 0;
			len = strlen(num);
			for (i = 0; i < len; i++)
			{
				n =n+ num[i] - '0';
			}
			// printf("%d\n",n);
			if (n < 10)
				break;

			sprintf(num,"%d",n);
		}
		printf("%d\n",n);
	}
	return 0;
}
