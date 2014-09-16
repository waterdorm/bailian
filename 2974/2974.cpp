#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	char str[80];
	char telNum[100000][9];
	char map[] = "22233344455566677778889999";
	
int compare(const void *elem1,const void *elem2)
{
	return (strcmp((char*)elem1,(char*)elem2));
}
void standardizeTel(int n)
{
	int j,k;
	for ( j = -1,k = -1; k < 8;)
	{
		j++;
		if ('-' == str[j])
			continue;
		k++;
		if (3 == k)
		{
			telNum[n][k] = '-';
			k++;
		}
		if (str[j] >= 'A' && str[j] <= 'Z')
		{
			telNum[n][k] = map[str[j]-'A'];
			continue;
		}
		telNum[n][k] = str[j];
	}
	telNum[n][k] = '\0';
	return;
}
int main(int argc, char** argv) {
	int n,i,j;
	bool noduplicate = true;
	scanf("%d",&n);
	for ( i = 0; i < n; i++)
	{
		scanf("%s",str);//输入电话号码
		standardizeTel(i); 
	}
	qsort(telNum,n,9,compare);//对输入电话排序
	noduplicate = true;
	for (i = 0; i < n;)
	{
		j = i;
		i++;
		while (i < n && strcmp(telNum[i],telNum[j]) == 0) i++;
		if (i - j >1)
		{
			printf("%s %d\n",telNum[j],i -  j);
			noduplicate = false;
		}
	}
	 if (noduplicate)
	 	printf("No duplicates.\n");
	return 0;
}
