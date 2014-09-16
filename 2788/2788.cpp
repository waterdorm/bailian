#include <iostream>
#include <cstdio>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m;
	int num;
	int level;
	int left,right;
	n = 1;
	m = 1;
	while ( scanf("%d %d",&m,&n) && n != 0 && m != 0) 
	{
		num = 1;

		left = m*2;
		right = m*2 + 1;
		level = 2*2;
		num = level - 1;

		while (1)
		{
			if ( n < left)
			{
				num = level / 2 - 1;
				break;
			}
			if ( n >= left && n <= right)
			{
				num = level - 1;
				num = num - (right - n);
				break;
			}
			if ( n > right)
			{
				level = level * 2;
				left = left * 2;
				right = right * 2 + 1;
			}
		}
		printf("%d\n",num);
	}

	return 0;
}

