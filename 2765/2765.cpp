#include <iostream>
#include <cstring>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double n10;//double有52位精度，在本题中是合适的。 
	char n8[20];
	int len;
	while (std::cin >> n8)
	{
		n10 = 0; 
		len = strlen(n8);
		for ( int i = len - 1; n8[i] != '.'; i--)
		{
			n10/=(double)(8.0);
			n10 = n10 + (double)(n8[i] - '0');
		}
			n10/=(double)(8.0);
		printf("%s [8] ",n8);
		printf("= %.45g [10]\n",n10);//位宽明明不够为什么会accept啊� 
	}
	return 0;
}
