#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int rev(int i)
{
	return i < 3? i+3:i-3;
}
int face(int &p,int &h,int &r,int move)
{
	int temp;
	if (move == 1){ // back操作，对face 和 right 进行反向
		p = rev(p);
		r = rev(r);
	}
	else if ( move == 2){
		temp = p; // left 操作，face面向right的反向。right等于原来的face面向。
		p = rev(r);
		r = temp;
		
	}
	else if (move == 3){// right 操作，right等于当前face的反向，而face等于当前right
		temp = rev(p);
		p = r;
		r =temp;
	}
	else if (move == 4){// up操作，head等于反向face，face等于当前head
		temp = h;
		h =rev(p);
		p = temp;
	}
	else if (move == 5){// down 操作head等于face，face等于反向head
		temp = h;
		h = p;
		p = rev(temp);
	}
	return 0;
}

int num[6][2] = {{0,1},{1,1},{2,1},{0,-1},{1,-1},{2,-1}};
char direct[6][8]={"forward","back","left","right","up","down"};
int main(int argc, char** argv) {
	int m;
	int n;
	char d[8];
	int dist;
	int tempdirect;
	int i,j,k;
	int point[3];
	int p,h,r;// face head right

	scanf("%d",&m);
	for (i = 0; i < m; i++)
	{
		memset(point,0,sizeof(int)*3);
		p = 0;
		h = 2;
		r = 1;
		scanf("%d",&n);
		for (j = 0; j < n; j++)
		{
			scanf("%s %d",d,&dist);
			for (k = 0; k < 6; k++)
			{	
				if (strcmp(d,direct[k]) == 0)
					break;
			}
			 
			face(p,h,r,k);
			// 通过num矩阵进行正负系数的添加。
			point[num[p][0]] += num[p][1]*dist;
		 // printf("%d %d %d %d\n",point[0],point[1],point[2],p);
		}
		printf("%d %d %d %d\n",point[0],point[1],point[2],p);
	}
	return 0;
}
