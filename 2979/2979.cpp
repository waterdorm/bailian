// 仔细看的话逻辑上并没有太复杂，只是没做过 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int f[30][1000];
// f[j, k]表示，取j 个候选人，使其辩控差为k 的所有方案中，
// 辩控和最大的那个方案（该方案称为"方案f(j, k)"）的辩控和。
int Path[30][1000];
// Path 数组用来记录选了哪些人
// 方案f(j, k)中最后选的那个候选人的编号，记在Path[j][k]中
int P[300]; // 控方打分
int D[300]; // 辩方打分
int Answer[30]; // 存放最终方案的人选

int CompareInt(const void * e1, const void * e2)
{
	return * ((int *) e1) - * ((int *) e2);
}
int main()
{
	int i, j, k;
	int t1, t2;
	int n, m;
	int nMinP_D; // 辩控双方总分一样时的辩控差
	int nCaseNo;// 测试数据编号
	nCaseNo=0;
	scanf("%d%d", &n, &m);
	while(n+m) {
		nCaseNo++;
		for(i=1;i<=n;i++)
			scanf("%d%d", &P[i], &D[i]);
		memset(f, -1, sizeof(f));
		memset(Path, 0, sizeof(Path));
		nMinP_D=m*20; // 题目中的辩控差为0，对应到程序中辩控差就是m*20
		f[0][nMinP_D]=0; // 选0 个人使得辩控差为nMinP_D 的方案，其辩控和就是0
		for(j=0;j<m;j++) { // 每次循环选出第j 个人，共要选出m 人
			for(k=0;k<=nMinP_D*2;k++) // 可能的辩控差的范围是[0, nMinP_D*2]
				if(f[j][k]>=0) { // 方案 f(j, k)可行
					for(i=1;i<=n;i++) // 在方案f(j, k)的基础上，挑下一个人，逐个试
						if(f[j][k]+P[i]+D[i]>f[j+1][k+P[i]-D[i]]) {
							t1=j; t2=k;
							while(t1>0&&Path[t1][t2]!=i) {
								t2-=P[Path[t1][t2]]-D[Path[t1][t2]];
								t1--;
							}
							if(t1==0) {
								f[j+1][k+P[i]-D[i]]=f[j][k]+P[i]+D[i];
								Path[j+1][k+P[i]-D[i]]=i;
							}
						}
				}
		}
		i=nMinP_D;
		j=0;
		while(f[m][i+j]<0&&f[m][i-j]<0)
			j++;
		if(f[m][i+j]>f[m][i-j])
			k=i+j;
		else
			k=i-j;
		printf("Jury #%d\n", nCaseNo);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",(k-nMinP_D+f[m][k])/2, (f[m][k]-k+nMinP_D)/2);
		for(i=1;i<=m;i++) {
			Answer[i]=Path[m-i+1][k];
			k-=P[Answer[i]]-D[Answer[i]];
		}
		qsort(Answer+1, m, sizeof(int), CompareInt);
		for(i=1;i<=m;i++)
			printf(" %d", Answer[i]);
		printf("\n");
		printf("\n");
		scanf("%d%d", &n, &m);
	}
	return 0;
}

