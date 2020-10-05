#include "headers.h"

void bonus3(char **comm,char historries[22][1024],int two[],int *sze,char *procname[1000])
{
    int i,j,k,l,m;
    char **pi=(char **)malloc(1000*sizeof(char*));
    int endfl=0;
    j=0;
    int a=0;
    int andor=0;
    int prev;
    m=0;
    while(1)
    {    k=0;
        prev=m;
         while(1)
        {
            if(comm[j]==NULL)
            {endfl=1;
              break;
            } 
            else if((!(strcmp(comm[j],"$")))||(!(strcmp(comm[j],"@"))))
            {m=j;break;}
            else
            {
                pi[k]=comm[j];
            }
            k++;
            j++;


        }
           pi[k]=NULL;
           j++;
           a++;
           if(a==1)
           {  runcomm(pi,historries,two,sze,procname);  }
           else
           {
             if(!(strcmp(comm[prev],"@")))
             {andor=1;}
             else
             {
                 andor=0;
             }
             if(andor==1&&global==1)
             {runcomm(pi,historries,two,sze,procname);}
             else if(andor==1&&global==-1)
             {if(endfl==1){break;}continue;}
             else if(andor==0&&global==1)
             { if(endfl==1){break;}continue;  }
             else
             {
                 runcomm(pi,historries,two,sze,procname);
             }
             
             
                    



           }






        if(endfl==1)
        {break;}
    }





}