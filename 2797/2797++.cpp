/* է��֮��ȷʵûʲô˼·,������������������,Ȼ��ͻȻ�뵽�������ֵ�����,�ٶȵ�Ȼ���Ƿǳ����...
������ʵ����һ�ָ��򵥵ķ���,�Ǿ��Ƕ������ַ�������֮��,ÿ���ַ�����ǰ׺������ʵ��������ǰһ���ͺ�һ���ַ�����ͬ����,
nLen = max(nOne, nTwo), nOne �� nTwo�ͷֱ����ǰ�ַ�����ǰ���ַ������沿�ֵĳ���+1���ֵ...
����д����д�ǳ���...ͬѧ����ʵ������,Ҳ���ɹ���...

Ȼ���Ҿ������д��һ���ֵ���...�����ҵ�д�����Ǻܱ�׼,��Ϊ��û�ο�ʲôģ��,�Լ�Ӳ�������ôд��...
�ҵ��뷨�ǿ�һ����̬������,��һ�������Ϊ��,���洢����,�ӵڶ�����㿪ʼ��Ϊ���ɿռ����...
��ʵ,���Ƕ�26���ֵ��������˸������ݵĸ����...
ʹ��������ĸ�����,�������26���������ܶ�...
�տ�ʼ�Ҿͼ���1-26�Ž��ֱ�Ϊa-z,��Ϊ26�����ĸ�,
������26������λ�����õ�������,û��ָ��,���滻����ָ��,���뿴�����������...

*/
#include <stdio.h>
#include <string.h>
#define LETTER_NUM 26
#define WORD_LEN_MAX 25
#define WORD_NUM_MAX 1030
#define NODE_MAX (WORD_LEN_MAX * WORD_NUM_MAX + 10)
struct WORD_TREE
{
    char ch;
    WORD_TREE* next[LETTER_NUM];
    int nTime;
};
WORD_TREE tree[NODE_MAX];
WORD_TREE* pFreeNode = tree + 1;// ��һ�������Ϊͷ���,���洢����
char szWords[WORD_NUM_MAX][WORD_LEN_MAX];
void AddToTree(char* pszStr)
{
    WORD_TREE* pTree = tree;
    while (*pszStr && pTree->next[*pszStr - 'a'])
    {
        pTree = pTree->next[*pszStr - 'a'];
        pTree->nTime++;
        ++pszStr;
    }
    while (*pszStr)
    {
        pFreeNode->ch = *pszStr;
        pFreeNode->nTime++;
        pTree->next[*pszStr - 'a'] = pFreeNode;
        pTree = pFreeNode;
        ++pszStr;
        ++pFreeNode;
    }
}
int FindPrefix(char* pszStr)
{
    WORD_TREE* pTree = tree;
    int nLen = 0;
    while (*pszStr)
    {
        ++nLen;
        pTree = pTree->next[*pszStr - 'a'];
        if (pTree->nTime <= 1)
        {
            break;
        }
        ++pszStr;
    }
    return nLen;
}
int main()
{
    int nCount = 0;
    while (scanf("%s", szWords[nCount]) != EOF)
    {
        AddToTree(szWords[nCount]);
        nCount++;
    }
    for (int i = 0; i < nCount; ++i)
    {
        int nLen = FindPrefix(szWords[i]);
        printf("%s ", szWords[i]);
        for (int j = 0; j < nLen; ++j)
        {
            putchar(szWords[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
