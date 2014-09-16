//@author langx
//G++4.4
#include<cstdio>
#include<cstring>

const int month[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,
31,29,31,30,31,30,31,31,30,31,30,31};
//month[0]��ʾ��������ÿ���µ�������month[1]��ʾ������ÿ���µ�������

int type(const int &y){
    if(y %4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;// ������
    return 0;//��������
}

int main(){
    int t, i, k,  hh, mm, ss, dd, mo, yy, days;
    int hr, mr, sr, dr, mor, yr, totalsrs;
    scanf("%d",&t);
    while ( t-- ){
        scanf("%d:%d:%d%d.%d.%d",&hh, &mm, &ss, &dd, &mo, &yy);
        days = (yy - 2000) * 365 + (yy - 1997) / 4 -
            (yy - 1901) / 100 + ( yy- 1601) / 400;//������Ӷ�һ��,���������꣬��ΪҪ���ݾ���ʱ������·ݵ�ʱ���ܺͼ���
			// yy - 2000 + (m -1) ��m ָȡ���ķ�ĸ������4,100,400, ����������ȡ���Ϳ����ˣ�������Ϊ��ʼ��ݣ�2000�����꣬������Ҫ����ȡ����  
        k = type(yy);
        for ( i = 0; i < mo - 1; ++i ){
            days += month[k][i];
        }
        days += dd - 1;//�����ȥ2000��1��1�յ�������
        yr = days / 1000;
        days -= yr * 1000;
        mor = days / 100 + 1;
        days %= 100;
        dr = days + 1;
        //������ȥ����"��"��
        totalsrs = (hh * 3600 + mm * 60 + ss) * 125 / 108;
        hr = totalsrs / 10000;
        totalsrs -= hr * 10000;
        mr = totalsrs / 100;
        sr = totalsrs - mr * 100;
        printf("%d:%d:%d %d.%d.%d\n", hr, mr, sr, dr, mor, yr);
    }
    return 0;
}
