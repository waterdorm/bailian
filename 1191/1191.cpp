#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int size = 8;
double min = 100000000;
double avg = 0;
int Chess[size][size];
int Mark[size][size];
int Buf[size*2];

int Count(int x1, int y1, int x2, int y2)
{
	int temp = 0;
	for ( int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
		 	temp += Chess[i][j];
	return temp; 
}
int Cut(double temp,int n, int x1, int y1, int x2, int y2,int N)
{

	double t = 0;
	if ( n > ((x2-x1)+(y2 - y1)))
		return 0;
	if ( n == 1)
	{
		Buf[n] = Count(x1,y1,x2,y2);
		temp += (Buf[1] - avg)*(Buf[1]-avg);
		temp = temp /N;
		if (temp < min)
		{
			min = temp;
		}

		return 0;
	}
	
	for ( int i =  x1; i < x2; i++)
	{
		Buf[n] = Count(x1,y1,i,y2);
		t = (Buf[n] - avg)*(Buf[n]-avg);
		temp = temp + t;
		if ( (temp / N) > min)
		{
			temp = temp - t;
			continue;
		}

		Cut(temp,n - 1,i + 1,y1,x2,y2,N);
		temp = temp - t;
	}
	for ( int i = x2; i > x1; i--)
	{
		Buf[n] = Count(i,y1,x2,y2);
		t = (Buf[n] - avg)*(Buf[n]-avg);
		temp = temp + t;
		if ( (temp / N) > min)
		{
			temp = temp - t;
			continue;
		}
		Cut(temp,n - 1,x1,y1,i - 1,y2,N);
		temp = temp - t;
	}
	for ( int i =  y1; i < y2; i++)
	{
		Buf[n] = Count(x1,y1,x2,i);
		t = (Buf[n] - avg)*(Buf[n]-avg);
		temp = temp + t;
		if ( (temp / N) > min)
		{
			temp = temp - t;
			continue;
		}
		Cut(temp,n - 1,x1,i + 1,x2,y2,N);
		temp = temp - t;
	}
	for ( int i = y2; i > y1; i--)
	{
		Buf[n] = Count(x1,i,x2,y2);
		t = (Buf[n] - avg)*(Buf[n]-avg);
		temp = temp + t;
		if ( (temp / N) > min)
		{
			temp = temp - t;
			continue;
		}
		Cut(temp,n - 1,x1,y1,x2,i - 1,N);
		temp = temp - t;
	}
}
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	avg = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			scanf("%d",&Chess[i][j]);
			avg = avg + Chess[i][j];
		}
		avg = avg / n;
	// printf("%f",avg);
	/*
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d",Chess[i][j]);
		printf("\n");
	}*/
	//printf("%d",Count(0,0,1,1));
	double temp = 0;
	Cut(temp,n,0,0,7,7,n);
	//Cut(n,0,0,2,2,n);
	min = sqrt(min);
	min = min * 1000;
	min +=0.5;
	int R = (int)(min);
	min = (double)(R)/1000;
	printf("%.3lf\n",min);	
	return 0;
}
