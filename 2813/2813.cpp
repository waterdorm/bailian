
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
//来自关灯问题的修改 
int enumate(int *MatrixInput,int *MatrixOutput,int high,int wide);
bool guess(int *MatrixInput,int *MatrixOutput,int high,int wide);

int main(int argc, char** argv) {
	int n,t;
	int k,i,j;
	k = 1;
	int MatrixInput[300];
	int MatrixOutput[300];
	char str[20];
	int wide,high;
	char c;
	int success;
	scanf("%d",&t);
	while( t > 0)
	{

		scanf("%d",&n);
		wide = n + 2;
		high = n + 1;
		for( i = 1; i < high; i++)
		{
			scanf("%s",str);
			for( j = 1; j < wide -1; j++)
			{
				if ( str[j-1] == 'y')
					*(MatrixInput + i*wide + j) = 0;
				else if (str[j-1] == 'w')
					*(MatrixInput + i*wide + j) = 1;
			}
		}

		for( i = 0; i < high; i++)
		{
			for( j = 0; j < wide; j++)
			{
				*(MatrixOutput + i*wide+ j) = 0;
			}
		}
		
		success = enumate(MatrixInput,MatrixOutput,high,wide);
		if (success <= n*n)
			printf("%d\n",success);
		else printf("inf\n");
		t--;
	}

	return 0;
}
int enumate(int *MatrixInput,int *MatrixOutput,int high,int wide)
{
	int Min = wide * high;
	int C;
	int i,j,k;
	bool result = false;
	int times;
	times = exp2(wide -2);
for( int m = 0; m < times; m++)
	{
		//就因为这里for循环用i，和下面的i重复了，拷贝代码害死人果然不错的。 
		result = guess(MatrixInput,MatrixOutput,high,wide);
		if (result == true)
		{
			k = 0;
			for( i = 1; i < high; i++)
			{
				for( j = 1; j < wide -1; j++)
				{
					if (*(MatrixOutput + i*wide + j) == 1)
						k++;

				}
			}
			if( k < Min)
				Min = k;
		}
		
		*(MatrixOutput+ wide + 1)+=1;
		C = 1;
		while (*(MatrixOutput + wide + C ) > 1)
		{
			*(MatrixOutput + wide + C )= 0;
			C++;
			*(MatrixOutput + wide + C )+=1;
		}
		
	}
	
	return Min;

	
} 
bool guess(	int *MatrixInput,int *MatrixOutput,int high,int wide)
{
	int i;
	for (i = 1; i < high - 1; i++)
	{
		for ( int j = 1; j < wide - 1; j++)
		//以为一排一排的灭掉，要保证下一排同列，保证灭掉前一排同列的 
		*(MatrixOutput+(i + 1)*wide + j) = (*(MatrixInput+ i*wide + j) + *(MatrixOutput + i*wide + j)+ *( MatrixOutput+ (i-1)*wide+j)+ *(MatrixOutput+i*wide+j-1)+ *(MatrixOutput+i*wide+j+1))%2;
	}
	for (int j = 1; j < wide - 1; j++)
	{
		if ( ( (*(MatrixInput+i*wide+j) + *(MatrixOutput+i*wide+j)+ *(MatrixOutput+(i-1)*wide+j)+ *(MatrixOutput+i*wide+j-1)+ *(MatrixOutput+i*wide+j+1))%2) != 0)
			return false;
	}
	return true;
} 
/*
	*/
