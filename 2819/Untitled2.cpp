#include<cstdio>
#include<cstring>
#define MAX_SIZE 200

char str[MAX_SIZE], tmp[MAX_SIZE];


void crypt(const int *p, const int &pl,int k){
   if(pl <= 1) return;
   int i, l;
      k = pl - k % pl;
   l = 0;
   for ( i = k; i < pl; ++i ){
     tmp[l++] = str[p[i]];
   }
   for ( i = 0; i < k; ++i ){
    	tmp[l++] = str[p[i]];
   }
   for ( i = 0; i < l; ++i ){
      str[p[i]] = tmp[i];
   }
}


int main(){
		int i, k1, k2, k3, a[MAX_SIZE], b[MAX_SIZE],c[MAX_SIZE], al, bl, cl;
   while ( ~scanf("%d%d%d",&k1,&k2,&k3) && (k1 + k2 + k3)){
     scanf("%s",str);
    al = bl = cl = 0;
    for ( i = 0; str[i] != '\0'; ++i ){
   		if(str[i] >= 'a' && str[i] <= 'i'){
   		a[al++] = i;
  }else if(str[i] >= 'j' && str[i] <= 'r'){
  		 b[bl++] = i;
  }else{
   		c[cl++] = i;
  }
   }
   crypt(a, al, k1);  
     crypt(b, bl, k2);
     crypt(c, cl, k3);
     printf("%s\n",str);
   }
   return 0;
}
