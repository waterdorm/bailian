#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAX_N 1000
#define INFINITE 1000000
// 因为这道题用递归实现二叉查找，穷举所有可能。如果动态规划的话，估计要从地面往上跳。
// 没有写，主要是输入输出处理比较麻烦，跳过了这个题 。
// 看到输入输出很烦人的很恶心 
int t, n, x, y, max;

struct Platform{
	int Lx, Rx, h;
};

Platform aPlatform[MAX_N + 10];
int aLeftMinTime[MAX_N + 10];
int aRightMinTime[MAX_N + 10];

int MyCompare( const void * e1, const void * e2 )
{
	Platform * p1, * p2;
	p1 = (Platform * ) e1;
	p2 = (Platform * ) e2;
	return p2->h - p1->h;
}
int MinTime( int L, bool bLeft )
{
	int y = aPlatform[L].h;
	int x;
	if( bLeft )
		x = aPlatform[L].Lx;
	else
		x = aPlatform[L].Rx;

	int i;

	for( i = L + 1;i <= n;i ++ ) {
		if( aPlatform[i].Lx <= x && aPlatform[i].Rx >= x)
			break;
	}
	if( i <= n ) {
		if( y - aPlatform[i].h > max )
			return INFINITE;
	}
	else {
		if( y > max )
			return INFINITE;
		else
			return y;
	}

	int nLeftTime = y - aPlatform[i].h + x - aPlatform[i].Lx;
	int nRightTime = y - aPlatform[i].h + aPlatform[i].Rx - x;

	if( aLeftMinTime[i] == -1 )
		aLeftMinTime[i] = MinTime(i, true);
	if( aRightMinTime[i] == -1 )
		aRightMinTime[i] = MinTime(i, false);

	nLeftTime += aLeftMinTime[i];
	nRightTime += aRightMinTime[i];

	if( nLeftTime < nRightTime )
		return nLeftTime;

	return nRightTime;
}

int main()
{
	scanf("%d", &t);
	for( int i = 0;i < t; i ++ ) {
		memset(aLeftMinTime, -1, sizeof(aLeftMinTime));
		memset(aRightMinTime, -1, sizeof(aRightMinTime));
		scanf("%d%d%d%d", &n, &x, &y, &max);
		aPlatform[0].Lx = x;
		aPlatform[0].Rx = x;
		aPlatform[0].h = y;
		for( int j = 1; j <= n; j ++ )
			scanf("%d%d%d", & aPlatform[j].Lx, & aPlatform[j].Rx, & aPlatform[j].h);
		qsort(aPlatform, n+1, sizeof(Platform), MyCompare);
		printf("%d\n", MinTime(0, true));
	}

	return 0;
}

