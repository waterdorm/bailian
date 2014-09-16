#include <stdio.h>
#include <string.h>
#define N_MAX 200 + 10
int main()
{
    int nN = 0;
    int nNArr[N_MAX];//密钥
    int nK = 0;
    char szMsg[N_MAX];
    char szMsgBckup[N_MAX];//字符串备份
    int nCir[N_MAX];//周期
    int nMsgLen = 0;
    int nPos = 0;
    int i, j;
    
    while (scanf("%d", &nN), nN != 0)
    {
        for (i = 1; i <= nN; ++i)
        {
            scanf("%d", &nNArr[i]);
        }
        
        for (i = 1; i <= nN; ++i)//计算周期
        {
            nPos = i;
            for (j = 1; ; ++j)
            {
                nPos = nNArr[nPos];
                if (nPos == i)
                {
                    nCir[i] = j;
                    break;
                }
            }
        }
        
        while (scanf("%d", &nK), nK != 0)
        {
            getchar();//销掉空格
            gets(szMsg + 1);
            nMsgLen = strlen(szMsg + 1);
            for (i = nMsgLen; i < nN; ++i)
            {
                szMsg[1 + i] = ' ';
            }
            szMsg[1 + nN] = '\0';
            strcpy(szMsgBckup + 1, szMsg + 1);
            
            for (i = 1; i <= nN; ++i)
            {
                nPos = i;
                int nTimes = nK % nCir[i];
                for (j = 1; j <= nTimes; ++j)
                {
                    nPos = nNArr[nPos];
                }
                szMsg[nPos] = szMsgBckup[i];
            }
            
            printf("%s\n", szMsg + 1);
        }
        printf("\n");
    }
    
    return 0;
}
