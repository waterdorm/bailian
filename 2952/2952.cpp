#include <iostream>
#include <cstdio>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 65
bool test(char b[],char a[])
{
    // printf("%s %s\n",a,b);
    bool B;
    int i,j,k,length;
	length = strlen(a);
	for ( i =0 ; i < length; i++)
	{
		if ((strncmp(a + i,b,length - i)==0) && (strncmp(b + length - i,a,i)==0))
				return true;
	}
    return false;
}
bool multiple(char num[],int len)
{
	char Temp[MAX];
	char n[MAX];
	int All[MAX];
	int an1[MAX];
	int an2[MAX];
	int T;
	int lenn;
	int i,j,k;
	
	for (i = 1; i <= len; i++)
	{
		
		memset(All,0,sizeof(All));
		memset(an1,0,sizeof(an1));
		memset(an2,0,sizeof(an2));
		sprintf(n,"%d",i);
		lenn = strlen(n);
		k = 0;
		for (j = 0; j < len; j++)
		{
			if ( num[j] != '0')
				break;
		}
		T = j; 
		for (j = len -1; j >= T; j--)
		{
			an1[k++] = num[j] - '0';
		}
		k = 0;
		for (j = lenn -1; j >= 0; j--)
		{
			an2[k++] = n[j] - '0';
		}
		for (j = 0; j < len; j++)
		{
			for (k = 0; k < lenn; k++)
				All[j + k] += an1[j]*an2[k];
		}
		for ( j = 0; j < MAX; j++ )
		{
			if (All[j] >= 10){
				All[j + 1] += All[j]/10;
				All[j]%=10;
			}
		}
		bool bStart = false;
		k = 0;
		for (j = len - 1; j >= 0; j--)
		{
			if (bStart)
				Temp[k++] = All[j] + '0';
			else if (All[j])
			{
				Temp[k++] = All[j] + '0';
				bStart = true;
			}
			if (!bStart)
				Temp[k++] = '0';
		}
		Temp[k] = '\0';
		if (!test(Temp,num))
			return false;
	}
	return true;
}
int main(int argc, char** argv) {
	char num[MAX];
	int len;
	int i,j;
	bool confirm;
	while (scanf("%s",num)!=EOF)
	{
		confirm = false;
		len = strlen(num);
		confirm = multiple(num,len);
		if (confirm)
			printf("%s is cyclic\n",num);
		else printf("%s is not cyclic\n",num);
	}
	return 0;
}
