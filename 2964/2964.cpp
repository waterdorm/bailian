#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int type(int n)
{
	if (n %4 != 0 || (n % 100 == 0 && n% 400 != 0)) return 0;
	else return 1; // 默认设置不会有3200年。 
}
int main(int argc, char** argv) {
	char week[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday","Friday"};
	int year[2] = {365,366};
	int month[2][12] = {31,28,31,30,31,30,31,31,30,31,30,31,\
						31,29,31,30,31,30,31,31,30,31,30,31};
	int days,dayofweek;
	int i = 0, j = 0;
	while(scanf("%d",&days) && days != -1)
	{
		dayofweek = days % 7;
		for (i = 2000; days >= year[type(i)]; i++)
			days -=year[type(i)];
		for (j = 0; days >= month[type(i)][j];j++)
			days -= month[type(i)][j];
		printf("%d-%02d-%02d %s\n",i,j+1,days + 1,week[dayofweek]);
		
	}
	return 0;
}
