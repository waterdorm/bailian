#include <iostream>
#include <cstring>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char szK1[] = {"abcdefghi"};
char szK2[] = {"jklmnopqr"};
char szK3[] = {"stuvwxyz_"};
int find(char *szS,int strlen,char *szK,char *szR,int k)
{
	char Index[200][2];
	char *p;
	int i,j;
	char c;
	j = 0;
	for (i = 0; i < strlen; i++)// �ҳ�����λ��һ������ݣ�����¼������ԭ�ַ����е�λ�� 
		{
			c = *(szS + i);
			p = strchr (szK,c);
			if ( p != NULL)
			{
				Index[j][0] = c;
				Index[j][1] = i;
				j++;
				//printf("%c ",c);
			}
			
		}
	if ( j == 0) return 0;// Ŀǰ����������������ж�j��ֵ�Ļ��������п��ܾ�runtime error ��
	// j == 0  ����ǰ�ַ����������е�ǰ�����ĸ���Ϳ��Է����ˡ�����Ĳ����Ͳ����� 
	int n = k%j;
	j = j - 1;
	if (n == 0)
	{
		for (i = 0; i <= j;i++)
		{
			szR[Index[i][1]] = Index[i][0];
		}
	}
	else{
			
		for (i = 0; i <= j - n; i++)
		{
			szR[Index[n + i][1]] = Index[i][0];
			//printf("%c ",szR[Index[n + i][1]]);
		}

		for (i = j - n + 1; i <= j; i++)
		{
			szR[Index[i - (j - n + 1)][1]] = Index[i][0];
			//printf("%c ",szR[Index[i - (j - n + 1)][1]]);
		}
	 		
		/*д�����Ƶ��ˣ����� 
		for (i = 0; i <= n; i++)
			szR[Index[j - n + i][1]] = Index[i][0];
		for (i = n + 1; i <= j; i++)
	 		szR[Index[i-n][1]] = Index[i][0];
	 		*/
	}
	
	return 0;
}
int main(int argc, char** argv) {
	int k1,k2,k3;
	char szS[200];
	char szR[200];
	int slen;

	while (scanf("%d%d%d",&k1,&k2,&k3) && (k1+k2+k3))
	{
		scanf("%s",szS);
		slen = strlen(szS);
		find (szS,slen,szK1,szR,k1);
		find (szS,slen,szK2,szR,k2);
		find (szS,slen,szK3,szR,k3);
		szR[slen] = '\0';
		printf("%s\n",szR);
	//	memset(szS,0,strlen(szS));
	}
	return 0;
}
