#include <iostream>
#include <cstdlib>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double Decimal(char a[],int B)
{
	double n = 0;
	double nB = 1;
	int i = 0;
	while (true)
	{
		if ( a[i] - '0' >= B)
			return -1;
		if ( '\0' == a[i])
			break;
		n = n* B;
		n= n + (a[i] - '0');¡//×¢ÒâÊı×éÖĞ×Ö·û´Ó¸ßÎ»µ½µÍÎ»£¬×Ô×óÍùÓÒ 
		i++;
		
	}
	return n;
}

int main(int argc, char** argv) {
	int nCases = 0;
	char a[8],b[8],sum[8],B;
	double da,db,dsum;//±íÊ¾¶ÔÓ¦Ê®½øÖÆµÄÊıÖµ 
	int i,j;
	scanf("%d",&nCases);
	for(i = 0;i < nCases; i++)
	{
		scanf("%s %s %s",a,b,sum);//scanfÊÇ´Ó×óÍùÓÒ¶ÁÈ¡£¬Í¬Ê±¿¼ÂÇ¿Õ¸ñ×÷Îª·Ö¸ô·û£¬Ò»¶¨²»ÒªÍü¼Ç 
		for ( j = 2; j <= 16; j++)
		{
			da = Decimal(a,j);
			db = Decimal(b,j);
			dsum = Decimal(sum,j);
			if ( da == -1 || db == -1 || dsum == -1) continue;//¿¼ÂÇ²»Âú×ãÊıÖÆµÄÇéĞÎ 
			//printf("%f %f %f\n",da,db,dsum);
			if( dsum == (da * db))
			{
				printf("%d\n",j);
				break;
			}
				
		}
		if ( j > 16)
			printf("%d\n",0);
	}
	return 0;
}
