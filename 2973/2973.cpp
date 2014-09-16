#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	unsigned long int n;
	char num[40];
	int i;
	int len;
	int B = 1;
	while(true)//(scanf("%d",&n),n != 0)
	{
		scanf("%s",num);
		len = strlen(num);
		B = 1;
		n = 0;
		for (i = len - 1; i >= 0; i--)
		{
			B = B * 2;
			n = n + (num[i] - '0')*(B - 1);
			//printf("%d ",i);
			
		}
		if (0 == n)
			break;
		printf("%d\n",n);
	}
	return 0;
}
