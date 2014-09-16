#include <cstdio>
#include <cstdlib>

int check(int nbegin,int nend,int nb[],int ne[],int nN)
{
	for (int i =0; i < nN + 1; i++)
	{
		if (nb[i] != 0 && ne[i] != 0)
		{
			if(nend < nb[i] || nbegin > ne[i])
				continue;
			else 
				return i;
		}

	}
	return -1;
}
int combine(int nbegin,int nend,int nb[],int ne[],int nN,int index)
{
	if (nbegin >= nb[index] && nend <= ne[index])
		;
	else if(nend >= nb[index] && nbegin <= nb[index])
		nb[index] = nbegin;
	else if(nbegin <= ne[index] && nend >= ne[index])
		ne[index] = nend;
}
int main(int argc, char** argv) {
	int nCases,i,j;
	int nL;
	int nbegin,nend;
	int nb[101] = {0},ne[101] = {0};
	int nN = 0;
	int index = -1;
	scanf("%d",&nL);
	scanf("%d",&nCases);
	scanf("%d%d",&nbegin,&nend);
	nb[0] = nbegin; ne[0] = nend;
	for (i = 0;i < nCases -1;i++)
	{
		scanf("%d%d",&nbegin,&nend);
		index = check(nbegin,nend,nb,ne,nN);
		while (index != -1)
		{
			printf("%d",index);
			combine(nbegin,nend,nb,ne,nN,index);
			index = check(nb[index],ne[index],nb,ne,nN);
			if (index != -1)
			{
				nbegin = nb[index];
				nend = ne[index];
			}
			else
			{
				nN++ ;
				nb[nN] = nbegin;
				ne[nN] = nend;
				printf("%d %d",nb[nN],ne[nN]);
			}
			index = -1;
		}
	
		
		
	}
	for (int i =0; i < nN; i++)
	{
		if (nb[i] != 0 && ne[i] != 0)
		{
			nL = nL - ne[i] + nb[i];
		}

	}
	printf("%d\n",nL);
	system("pause");
	return 0;
}
