#include <cstdio>
#include <cstdlib>


int main(int argc, char** argv) {
	int nCases,i,j;
	int nL;
	int nbegin,nend;
	bool bL[10001] = {false};//用数组记录的想法，很猥琐，不过很有效 
	scanf("%d",&nL);
	for (i = 0;i <= nL;i++)
	{
		bL[i]=true;
	}
	scanf("%d",&nCases);
	for (i = 0;i < nCases;i++)
	{
		scanf("%d%d",&nbegin,&nend);
		for (j = nbegin;j <= nend; j++ )
		{
			bL[j] = false;
		}
		
	}
	for(i = 0,j = 0; i <= nL; i++)
	{
		if(true == bL[i])
			j++;
	}
	printf("%d\n",j);
	system("pause");
	return 0;
}
