#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int sub(int a,int b)
{
	if (a >= b)
	return a - b;
	else return 0;
}
int main(int argc, char** argv) {
	int nZeroCount = 0;
	int nBox;
	int nOrder[6];
	while (nZeroCount != 6)
	{
		nZeroCount = 0;
		nBox = 0;
		for (int i = 0; i < 6; i++)
		{
			scanf("%d",&nOrder[i]);
			if(0 == nOrder[i])
			nZeroCount++;
		}
		if (6 == nZeroCount) break;
		nBox = nBox + nOrder[5];
		nOrder[5] = 0;
		if (nOrder[4] > 0)
		{
			nBox = nBox + nOrder[4];
			nOrder[0] = sub(nOrder[0],nOrder[4]*11);
			nOrder[4] = 0;
		}
		if (nOrder[3] > 0)
		{
			nBox = nBox + nOrder[3];
			nOrder[1] = sub(nOrder[1],nOrder[3]*5);
			if (nOrder[3]*5 - nOrder[1] > 0)
			nOrder[0] = sub(nOrder[0],(nOrder[3]*5 - nOrder[1])*4);
			nOrder[3] = 0;
		}
		if (nOrder[2] > 0)
		{
			nBox = nBox + nOrder[2]/4;
			if (3 == nOrder[2]%4)
			{
				nBox = nBox +1;
				nOrder[1] = sub(nOrder[1],1);
				if (1 - nOrder[1] > 0)
				nOrder[0] = sub(nOrder[0],(1 - nOrder[1])*4);
				nOrder[0] = sub(nOrder[0],5);
			}
			if (2 == nOrder[2]%4)
			{
				nBox = nBox +1;
				nOrder[1] = sub(nOrder[1],3);
				if (3- nOrder[1] > 0)
				nOrder[0] = sub(nOrder[0],(3 - nOrder[1])*4);
				nOrder[0] = sub(nOrder[0],6);
			}
			if (1 == nOrder[2]%4)
			{
				nBox = nBox +1;
				nOrder[1] = sub(nOrder[1],5);
				if (5 - nOrder[1] > 0)
				nOrder[0] = sub(nOrder[0],(5 - nOrder[1])*4);
				nOrder[0] = sub(nOrder[0],7);
			}
			nOrder[2] = 0;
		}
		if (nOrder[1] > 0)
		{
			nBox = nBox + nOrder[1]/9;
			if ( nOrder[1]%9 > 0)
			{
				nBox = nBox + 1;
				nOrder[0] = sub(nOrder[0],36 - (nOrder[1]%9)*4);
				nOrder[1] = 0;
			}
		}
		if (nOrder[0] > 0)
		{
			nBox = nBox + nOrder[0]/36;
			if ( nOrder[0]%36 > 0)
			{
				nBox = nBox + 1;
				nOrder[0] = 0;
			}
		}
		printf("%d\n",nBox);
	}
	return 0;
}
