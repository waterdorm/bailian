#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define LEN 22
#define ROW 1001
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	char szA[ROW][LEN];
	char szB[ROW][LEN];
int cmp (const void *a,const void *b)
{
	return (strcmp((char *)a,(char *)b));
}

int FindPosition(char* pszWord, int nItemNum)
{
    int nBeg = 0, nEnd = nItemNum - 1;
    int nCmp = 0;
    
    while (nBeg <= nEnd)
    {
        int nMid = (nBeg + nEnd) / 2;
        nCmp = strcmp(pszWord, szA[nMid]);
        if (nCmp == 0)
        {
            return nMid;
        }
        else if (nCmp < 0)
        {
            nEnd = nMid - 1;
        }
        else
        {
            nBeg = nMid + 1;
        }
    }
    
    return -1;
}

int strc(char *a,char *b)
{
	int i = 0;
	while ( *(a + i) == *(b + i))
		i++;
	i++; 
	return i;
}

int main(int argc, char** argv) {


	int i,j,k;
	int num,temp;
	i = 0;
	while (scanf("%s",szA[i])!= EOF)
			i++;
	for (j = 0; j < i; j++)
	{
		sscanf(szA[j],"%s",szB[j]);
		//printf("%s ",szB[j]);
	}

	qsort (szA,i,sizeof(szA[0]),cmp);// �Բ��ˣ���Ȼֱ��дROW����һ��������ѽ 
//	for ( j = 0; j < i; j++)
//	   printf("%s ",szA[j]);
	//   printf("\n");
	for ( j = 0; j < i; j++)
	{
		//printf("%s ",szA[j]);
		k = FindPosition(szB[j],i); 
	//	printf("%d ",k);
		if (k == 0)
		{
			num = strc(szA[k],szA[k+1]);
			szA[k][num] = '\0';
		//	printf("%d ",num);
			printf("%s %s\n",szB[j],szA[k]);
		}
		else if (k == i - 1)
		{
			num = strc(szA[k-1],szA[k]);
			szA[k][num] = '\0';
		//	printf("%d ",num);
			printf("%s %s\n",szB[j],szA[k]);
		}
		else{
			num = strc(szA[k-1],szA[k]);
			if (strc(szA[k],szA[k+1])> num)
				num = strc(szA[k],szA[k+1]);
			szA[k][num] = '\0';
			//printf("%d ",num);
			printf("%s %s\n",szB[j],szA[k]);
		}
	}
	
	
	return 0;
}

// strcmp ��ͬƽ̨���ز�ͬ���еĻ᷵�ص�һ����ͬλ�ã��е�ֻ�����Ƿ���ȡ�1 0 -1�ȡ� 
