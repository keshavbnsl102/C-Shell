
 #include "headers.h"


void bg(char **comm,int proc[],char *procname[1000])
{  global=1;
    if(comm[1]==NULL)
   {global=-1;printf("error : give the job number too\n");return;}
   if(comm[2]!=NULL){global=-1;printf("TOO MANY ARGUMENTS\n");return;}
    int i,j,k;
    for(i=0;comm[1][i]!='\0';i++)
    { if(comm[1][i]<48||comm[1][i]>57)
            {global=-1;printf("INVALID job number\n");return;}
    }

     int x=atoi(comm[1]);
      j=0;
    for(i=0;i<1000;i++)
    {if(proc[i]<=0)
            {continue;}
          j++;
          if(j==x)
          {
		  kill(proc[i],SIGCONT);
		  break;


          }
    }
    if(j!=x)
    {global=-1;printf("NO SUCH JOB nUMBER\n");}



}



