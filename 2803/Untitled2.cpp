/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
const int max  = 8;
int count = 0;

int Cut(int sum,int &Max, const int n, char paper[max], int m, int sublen,const int L)
{
	if ( m == 0)
	{
		if ( sum > Max )
		{	
			Max = sum;
			count = 0;
		}
		if ( sum == Max)
			count++;
		return 0;
	}
	if ( m < 0 || sublen > m)
		return 0;
	//printf("%d-",m);

	char buf[max];
	
	strncpy(buf,paper + L - m,sublen);
	buf[sublen] = '\0';
	sum += atoi(buf);
	//printf("%d %d* %d %d\n",sum,m,atoi(buf),Max);
	if ( sum > n)
	{
		return 0;
	}	
	Cut(sum,Max,n,paper,m - sublen,1,L);
	
	
	sum -= atoi(buf);
	Cut(sum,Max,n,paper,m ,sublen + 1,L);
}
int main(int argc, char** argv) {
	int n;
	int Res;
	char paper[max];
	int Max;
	while (scanf("%d%s",&n,paper) && n != 0)
	{
		count = 0;
		if ( n == atoi(paper))
			printf("%d %s\n",n,paper);
		Max = 0;
		Res = Cut(0,Max,n,paper,strlen(paper),1,strlen(paper));
		printf("%d\n",Max);
	}
	return 0;
}*/
