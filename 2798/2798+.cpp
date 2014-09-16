#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
 char input[10001];
 int nCase;
 int i,j;
 int length;
 int temp;
 int sum;
 scanf("%d",&nCase);
 for(i=0;i<nCase;i++)
 {
  strcpy(input,"");
  scanf("%s",input);
  length=strlen(input);
  temp=length%4;
  sum=0;
  if(temp){
  for(j=0;j<temp;j++)
  {
   sum+=(input[j]-'0')*pow(2,temp-1-j);
  }
  printf("%X",sum);
  }
  for(j=temp;j<length;j=j+4)
  {
   printf("%X",(input[j]-'0')*8+(input[j+1]-'0')*4+(input[j+2]-'0')*2+(input[j+3]-'0')*1);
  }
  printf("\n");
 }
 return 0;
}
