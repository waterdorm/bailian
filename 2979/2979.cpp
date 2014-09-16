// ��ϸ���Ļ��߼��ϲ�û��̫���ӣ�ֻ��û���� 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int f[30][1000];
// f[j, k]��ʾ��ȡj ����ѡ�ˣ�ʹ���ز�Ϊk �����з����У�
// ��غ������Ǹ��������÷�����Ϊ"����f(j, k)"���ı�غ͡�
int Path[30][1000];
// Path ����������¼ѡ����Щ��
// ����f(j, k)�����ѡ���Ǹ���ѡ�˵ı�ţ�����Path[j][k]��
int P[300]; // �ط����
int D[300]; // �緽���
int Answer[30]; // ������շ�������ѡ

int CompareInt(const void * e1, const void * e2)
{
	return * ((int *) e1) - * ((int *) e2);
}
int main()
{
	int i, j, k;
	int t1, t2;
	int n, m;
	int nMinP_D; // ���˫���ܷ�һ��ʱ�ı�ز�
	int nCaseNo;// �������ݱ��
	nCaseNo=0;
	scanf("%d%d", &n, &m);
	while(n+m) {
		nCaseNo++;
		for(i=1;i<=n;i++)
			scanf("%d%d", &P[i], &D[i]);
		memset(f, -1, sizeof(f));
		memset(Path, 0, sizeof(Path));
		nMinP_D=m*20; // ��Ŀ�еı�ز�Ϊ0����Ӧ�������б�ز����m*20
		f[0][nMinP_D]=0; // ѡ0 ����ʹ�ñ�ز�ΪnMinP_D �ķ��������غ;���0
		for(j=0;j<m;j++) { // ÿ��ѭ��ѡ����j ���ˣ���Ҫѡ��m ��
			for(k=0;k<=nMinP_D*2;k++) // ���ܵı�ز�ķ�Χ��[0, nMinP_D*2]
				if(f[j][k]>=0) { // ���� f(j, k)����
					for(i=1;i<=n;i++) // �ڷ���f(j, k)�Ļ����ϣ�����һ���ˣ������
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

