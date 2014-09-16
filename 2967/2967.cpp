//@author langx
//G++4.4
#include<cstdio>
#include<cstring>

const int month[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,
31,29,31,30,31,30,31,31,30,31,30,31};
//month[0]表示非闰年里每个月的天数，month[1]表示闰年里每个月的天数。

int type(const int &y){
    if(y %4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;// 是闰年
    return 0;//不是闰年
}

int main(){
    int t, i, k,  hh, mm, ss, dd, mo, yy, days;
    int hr, mr, sr, dr, mor, yr, totalsrs;
    scanf("%d",&t);
    while ( t-- ){
        scanf("%d:%d:%d%d.%d.%d",&hh, &mm, &ss, &dd, &mo, &yy);
        days = (yy - 2000) * 365 + (yy - 1997) / 4 -
            (yy - 1901) / 100 + ( yy- 1601) / 400;//逢闰年加多一天,不包括当年，因为要根据具体时间进行月份的时间总和计算
			// yy - 2000 + (m -1) ：m 指取整的分母，例如4,100,400, 本来是向下取整就可以了，但是因为起始年份，2000是闰年，所以需要向上取整。  
        k = type(yy);
        for ( i = 0; i < mo - 1; ++i ){
            days += month[k][i];
        }
        days += dd - 1;//算出逝去2000年1月1日的总天数
        yr = days / 1000;
        days -= yr * 1000;
        mor = days / 100 + 1;
        days %= 100;
        dr = days + 1;
        //当天逝去的总"秒"数
        totalsrs = (hh * 3600 + mm * 60 + ss) * 125 / 108;
        hr = totalsrs / 10000;
        totalsrs -= hr * 10000;
        mr = totalsrs / 100;
        sr = totalsrs - mr * 100;
        printf("%d:%d:%d %d.%d.%d\n", hr, mr, sr, dr, mor, yr);
    }
    return 0;
}
