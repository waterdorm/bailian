#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	char list[100][101];

void strrev(char* str)
{
int i,len;char c;
len=strlen(str);
for(i=0;i<len/2;i++)
{
c=str[i];
str[i]=str[len-1-i];
str[len-1-i]=c;
}
str[len]='\0';

}

int SearchMaxSubStr(int n,char szStr[])
{
	int sourceStrlen = strlen(szStr);
	int subStrlen = sourceStrlen;
	int i;
	int j = 0;
	bool foundMaxSubStr;
	
	char subStr[101],revsubStr[101];
	while (subStrlen > 0)
	{
		for (i = 0; i <= sourceStrlen - subStrlen; i++)
	{
		
		strncpy(subStr,szStr + i,subStrlen);
		strncpy(revsubStr,szStr + i,subStrlen);
		subStr[subStrlen] = '\0';
		revsubStr[subStrlen] = '\0';
		strrev(revsubStr);
		foundMaxSubStr = true;
		
		for (j = 0; j < n; j++)
		{
			if ((strstr(list[j],subStr) == NULL) && (strstr(list[j],revsubStr) == NULL))
			{
				//printf("%s *",list[j]);
				
				foundMaxSubStr = false;
				break;
			}
		}
		//printf("%s %s %s %d %d %d %d\n",szStr,subStr,revsubStr,sourceStrlen,i,foundMaxSubStr,subStrlen);
		if (foundMaxSubStr) return subStrlen;
		
		
	
	}
		subStrlen--;
	}

	return 0;
}
int main(int argc, char** argv) {
	int t;
	int n = 100;
	int minLen;
	int maxSubLen;
	int minIndex;
	
	int i,j;
	scanf("%d",&t);
	for ( i = 0; i < t; i++)
	{
		minLen = 101;
		minIndex = 0;
		scanf("%d",&n);
		j = 0;
		while (j < n)
		{
			
			scanf("%s",list[j]);
			if (strlen(list[j]) < minLen)
			{
				minIndex = j;
				minLen = strlen(list[j]);
			}
			j++;
		}
		maxSubLen = SearchMaxSubStr(n,list[minIndex]);

		printf("%d\n",maxSubLen);
		
	}
	//system("pause");
	return 0;
}
