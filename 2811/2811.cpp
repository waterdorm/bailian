#include <iostream>
#include <cstdio>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define HEIGHT 6
#define WIDTH 8
//扩大以便简化按灯位置区别 
//参考答案吧，比我想的简洁 
//还是不够严谨啊，有点乱来，没有整理或者思考，观看形式不行啊，要保证写东西有逻辑，而不是凭感觉 
void enumate(int MatrixInput[HEIGHT][WIDTH],int MatrixOutput[HEIGHT][WIDTH]);
bool guess(	int MatrixInput[HEIGHT][WIDTH],int MatrixOutput[HEIGHT][WIDTH]);

int main(int argc, char** argv) {
	int n;
	int k,i,j;
	k = 1;
	int MatrixInput[HEIGHT][WIDTH];
	int MatrixOutput[HEIGHT][WIDTH];

	scanf("%d",&n);
	while( n > 0)
	{

		for( i = 1; i < HEIGHT; i++)
		{
			for( j = 1; j < WIDTH -1; j++)
			{
				scanf("%d",*(MatrixInput + i) + j);
			}
		}
		for( i = 0; i < HEIGHT; i++)
		{
			for( j = 0; j < WIDTH; j++)
			{
				MatrixOutput[i][j] = 0;
			}
		}
		printf("PUZZLE #%d\n",k);
		enumate(MatrixInput,MatrixOutput);

		for( i = 1; i < HEIGHT; i++)
		{
			for( j = 1; j < WIDTH -1; j++)
			{
				printf("%d",MatrixOutput[i][j]);
				if ( j != WIDTH - 2)
					printf(" ");
			}
			printf("\n");

		}
		n--;
		k++;
	}
	system("pause");
	return 0;
}
void enumate(int MatrixInput[HEIGHT][WIDTH],int MatrixOutput[HEIGHT][WIDTH])
{
	int C;
	bool result;
	while(guess(MatrixInput,MatrixOutput) != true)
	{
		MatrixOutput[1][1]++;
		C = 1;
		while (MatrixOutput[1][C] > 1)
		{
			MatrixOutput[1][C] = 0;
			C++;
			MatrixOutput[1][C]++;
		}

	}
	
} 
bool guess(	int MatrixInput[HEIGHT][WIDTH],int MatrixOutput[HEIGHT][WIDTH])
{
	int i;
	for (i = 1; i < HEIGHT - 1; i++)
	{
		for ( int j = 1; j < WIDTH - 1; j++)
		//以为一排一排的灭掉，要保证下一排同列，保证灭掉前一排同列的 
		MatrixOutput[i + 1][j] = (MatrixInput[i][j] + MatrixOutput[i][j]+ MatrixOutput[i - 1][j]+ MatrixOutput[i][j - 1]+ MatrixOutput[i][j + 1])%2;
	}
	for (int j = 1; j < WIDTH - 1; j++)
	{
		if ( ( (MatrixInput[i][j] + MatrixOutput[i][j]+ MatrixOutput[i - 1][j]+ MatrixOutput[i][j - 1]+ MatrixOutput[i][j + 1])%2) != 0)
			return false;
	}
	return true;
} 

