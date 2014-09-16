#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 100
#define DEBUG

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int compare(const void* a, const void* b)
{
  return strcmp((char*)a, (char*)b);
}

int Tree(char *Data,int &index, int depth,int size)
{
	int len;
	int FileIndex = 0;

	char File[MAX][MAX];
	char buf[MAX];

	while ( index < size)
	{
		len = sprintf(buf,"%s",Data+index);
		index = index + len + 1;
		if (buf[0] == ']')
			break;
		if (buf[0] == 'f')
		{
			memcpy(File + FileIndex,buf,strlen(buf)+1);
			FileIndex++;
		}
		if ( buf[0] == 'd')
		{
			for ( int j = 0; j <= depth; j++)
				printf("|     ");
			printf("%s\n",buf);
			Tree(Data,index,depth + 1,size);
		}
	}
	if ( FileIndex > 1)
		qsort(File,FileIndex,sizeof(File[0]),compare);
	for (int i = 0; i < FileIndex; i++)
	{
		for ( int j = 0; j < depth; j++)
			printf("|     ");
		printf("%s\n",File[i]);
	}
	return 0;
	
}
int main(int argc, char** argv) {
	char Data[MAX*MAX];
	char buf[MAX];
	int count = 0;
	int index = 0;
	int a = 0;
	while (scanf("%s",buf) && buf[0] != '#')
	{
		index = 0;
		while ( buf[0] != '*')
		{
			memcpy(Data+index,buf,strlen(buf)+1);
			index+=strlen(buf)+1;
			scanf("%s",buf);
		}
		count++;
		
		printf("DATA SET %d:\nROOT\n",count);
		
		a = 0;
		Tree(Data,a,0,index);
		printf("\n");
		
	}
	return 0;
}
