#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//��ֻ��˵���൱����ˣ�������ļ򵥶��� 
double exp()
{
	char a[11];
	scanf("%s",a);
	switch(a[0])
	{
		case '*': return exp()*exp();
		case '-': return exp()-exp();
		case '+': return exp()+exp();
		case '/': return exp()/exp();
		default: return  atof(a);
	} 
}
int main(int argc, char** argv) {
	double n;
	n = exp();
	printf("%f",n); 
	return 0;
}
