#include <iostream>
#include <cstdio>
#include <iomanip> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a[3][3];
	int b[3][3];
	int c[3][3];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			scanf("%d",&(a[i][j]));
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			scanf("%d",&(b[i][j]));
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			c[i][j] = b[i][j] + a[i][j];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			std::cout << std::setw(4) << c[i][j];
		std::cout<<std::endl;		
	}
	return 0;
}
