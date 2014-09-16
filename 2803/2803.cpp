#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
const int max  = 8;
int count = 0;
int Q[max];
int A[max];
int num;
int Maxnum;
/* ��������õ��˵ݹ�ĵݼ�˼�룬�� f(m,sub) = f(m-sub,1)+f(m,sub +1) 
 ��˵�������� m ������Ҫôǰ sub �����ѣ�sub ����Ϊ 1 ������ m ��ǰ�����ѣ� sub ������
 ͬʱ sub �������ܴ��� m ����֤�ݹ�����ȷ�Ľ�ֹ�� ֻ��˳����ϣ�û���漰������ 
 ���������ݱ���·�������ݹ��ָ�������ȡ���ֵʱ�������Ӧ��·���� */
int Cut(int sum,int &Max, const int n, char paper[max], int m, int sublen,const int L)
{

	if ( sum > n)
	{
		return 0;
	}	
	if ( m == 0)
	{
		if ( sum > Max )
		{	
			Max = sum;
			count = 1;
			memcpy(A,Q,sizeof(Q));
			Maxnum = num;
			// num = 0;
			return 1;
		}
		if ( sum == Max)
			count++;
	}
	if ( m < 0 || sublen > m)
		return 0;
	//printf("%d-",m);

	char buf[max];
	
	strncpy(buf,paper + L - m,sublen);
	buf[sublen] = '\0';
	sum += atoi(buf);
	Q[num] = atoi(buf);
	num++;
	// printf("%d %d %d %d\n",sum,atoi(buf),Max,num);

	Cut(sum,Max,n,paper,m - sublen,1,L);
	
	num--;
	sum -= atoi(buf);
	
	Cut(sum,Max,n,paper,m ,sublen + 1,L);
	return 0;
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
		{
			printf("%d %s\n",n,paper);
			continue;
		}

		Max = 0;
		num=0;
		Maxnum = 0;
		memset(Q,0,sizeof(Q));
		memset(A,0,sizeof(A));
		Res = Cut(0,Max,n,paper,strlen(paper),1,strlen(paper));
		if ( count > 1)
			printf("rejected\n");
		else if ( Max == 0)
			printf("error\n");
		else {
			printf("%d",Max);
			for ( int i = 0; i < Maxnum; i++)
				printf(" %d",A[i]);
			printf("\n");
		}
	}
	return 0;
}
