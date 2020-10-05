#include "headers.h"
int mina(int a,int b)
{if(a<b)
  {return a;}
  else
  {
      return b;
  }
  

}


void histo(char **comm,char his[22][1024])
{
  int i=0,y=0;
  int num=1;
  int x;
  if(comm[2]!=NULL)
  { printf("ERROR: TOO MANY ARGUMENTS\n");global=-1;return ;  }
  
  for(i=0;his[i][0]!='\0';i++)
  {  y++;}
  if(comm[1]!=NULL)
  { x=atoi(comm[1]);
  if(x==0){printf("ARGUMENT is not an integer\n");global=-1;return ;}
  }
  else
  {x=y;}
  int a =mina(10,y);
    a=mina(x,a);
  for(i=y-a;his[i][0]!='\0';i++)
  {  //printf("YES\n");
      printf("%d. %s\n",num,his[i]);
      num++;
  }
  

}