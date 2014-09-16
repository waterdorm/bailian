/* ��һ���ܼ򵥵���Ŀ,���һ����֪����ʲô������,��Ȼ����ǲ��ҵĻ�,˳������ǲ��е�,
����һ,����map,������map<string, string>���ֵ�,ע�ⲻҪ�뵱Ȼ��map<char*, char*>,
�����ö�̬�����ڴ�,���߻����ȿ������������ֵ�,�������Ƕ��˷����ڴ�...
����+����Ҳ�����,��Ϊ������ȷʵ�ܴ�,������ĿҲ������c��io����,���������ٽ���map<string, string>
�м仹��ת��һ��...
��֮������⻹�Ǻ�˳����,��wa��һ��,ԭ����2��д����,��Ҳ�ܾ�û��oj��д2����...
*/
// ��������:
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MAX_WORD_LEN 11
#define MAX_DICTION_ITEM (100000 + 10)

using std::sort;

struct Dictionary
{
    char szWord[MAX_WORD_LEN];
    char szEnglish[MAX_WORD_LEN];
};

Dictionary diction[MAX_DICTION_ITEM];

bool CmpDictionItem(Dictionary one, Dictionary two)
{
    return strcmp(one.szWord, two.szWord) < 0;
}

int FindEnglish(char* pszWord, int nItemNum)
{
    int nBeg = 0, nEnd = nItemNum - 1;
    int nCmp = 0;
    
    while (nBeg <= nEnd)
    {
        int nMid = (nBeg + nEnd) / 2;
        nCmp = strcmp(pszWord, diction[nMid].szWord);
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

int main()
{
    char szStr[30];
    char szWord[MAX_WORD_LEN];
    int nCount = 0;
    int nAnsItem = 0;
    
    while (fgets(szStr, 29, stdin), szStr[0] != '\n')
    {
        sscanf(szStr, "%s%s", diction[nCount].szEnglish, diction[nCount].szWord);
        ++nCount;
    }
    sort(diction, diction + nCount, CmpDictionItem);
    while (scanf("%s", szWord) == 1)
    {
        if ((nAnsItem = FindEnglish(szWord, nCount)) != -1)
        {
            printf("%s\n", diction[nAnsItem].szEnglish);
        }
        else
        {
            printf("eh\n"); 
        }
    }
    
    return 0;
}
/* ��ʵ�ҵ���ҪĿ����Ϊ��ָ�����ֵ�д��,��ҿ��ҵ�FindEnglish����,���ݵ�������ĵ�ַ������ĳ���,
Ȼ����д�������ʱ���õ���[]����ʽ,������ȷ��,��ȷ��,��������Ҫ������Ҫ����ѭ����������<����
<=,��ʵ��Ҳ�ܺ��ж�,��Ϊ�Ͻ���½綼�ܹ�ȡ��,����=�ǳ�����...�����޸�right��ʱ��,���뽫right = mid - 1,
ԭ��Ҳ����Ϊ������ȷ��,
����������ϲ�ȷ����,��ô�Ⱥžͱ���ȥ��,����rightҲֻ���޸�Ϊmid,��Ϊmid-1����ȷ����,��mid�����ϲ�ȷ��...
�뵽����̶ȵĻ�,�Ժ�дֻ��Ψһ����־�Ӧ�ò��������...����д����������������������С��Ķ��ֻ���Ҫ��������...*/
