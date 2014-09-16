#include <cstdio>
#include <cstdlib>
#include <bitset>
using namespace std;
int main(int argc, char** argv) {
	int nCases,i,j;
	int nL;
	int nbegin,nend;
	bitset<10010> bL;
	//bL.reset();
	// bool bL[10001] = {false};// 用数组记录的想法，很猥琐，不过很有效 
	scanf("%d",&nL);
	for (i = 0;i <= nL;i++)
	{
		bL.set(i);
	}
	scanf("%d",&nCases);
	for (i = 0;i < nCases;i++)
	{
		scanf("%d%d",&nbegin,&nend);
		for (j = nbegin;j <= nend; j++ )
		{
			bL.reset(j);
		}
		
	}
	for(i = 0,j = 0; i <= nL; i++)
	{
		if(true == bL.test(i))
			j++;
	}
	printf("%d\n",j);
	//system("pause"); // 多次提交不成功居然是因为这句runtime error 
	return 0;
}
