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
	// bool bL[10001] = {false};// �������¼���뷨�����������������Ч 
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
	//system("pause"); // ����ύ���ɹ���Ȼ����Ϊ���runtime error 
	return 0;
}
