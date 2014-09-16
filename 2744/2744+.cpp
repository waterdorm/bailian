#include <stdio.h>
#include <string.h>

int t, n;
char str[100][101];

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
 int searchMaxSubString(char* source) {
int subStrLen = strlen(source), sourceStrLen = strlen(source);
int i, j;
bool foundMaxSubStr;
char subStr[101], revSubStr[101];
 while ( subStrLen > 0 ) {// 搜索不同长度的子串，从最长的子串开始搜索
 for (i = 0; i <= sourceStrLen - subStrLen; i++) {
 // 搜索长度为subStrLen 的全部子串
 strncpy(subStr, source+i, subStrLen);
 strncpy(revSubStr, source+i, subStrLen);
 subStr[subStrLen] = revSubStr[subStrLen] = '\0';
 strrev(revSubStr);
 foundMaxSubStr = true;
 for( j = 0; j < n; j++)
 if ( strstr(str[j], subStr) == NULL && strstr(str[j], revSubStr) == NULL ) {
 foundMaxSubStr = false;
 break;
 }
 if (foundMaxSubStr) return(subStrLen);
 }
 subStrLen--;
 }

 return(0);
 }

 int main()
 {
 int i, minStrLen, subStrLen;
 char minStr[101];

 scanf("%d", &t);
 while(t--) {
 scanf("%d", &n);
 minStrLen = 100;
 for (i = 0; i < n; i++) {// 输入一组字符串
 scanf("%s", str[i]);
 if ( strlen(str[i]) < minStrLen ) {// 寻找输入字符串中的最短字符串
 strcpy(minStr, str[i]);
 minStrLen = strlen(minStr);
 }
 }
 subStrLen = searchMaxSubString(minStr);// 搜索满足条件的最长字符串
 printf("%d\n", subStrLen);
 }
 return 0;
 }
