#include "headers.h"
int flag1=0,flag2=0;
void handle1(int sig)
{ flag1=1;}
void handle2(int sig)
{flag2=1;}

void fg(char **comm,int proc[],char *procname[1000],int *sze)
{   global=1;
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
	  int g=0;
	  if(j==x)
	  {     int a;
		kill(proc[i],SIGCONT);
                signal(SIGINT,handle1);


                tcsetpgrp(STDIN_FILENO,proc[i]);

                      signal(SIGTTIN,SIG_IGN);

                      signal(SIGTTOU,SIG_IGN);

                      waitpid(proc[i],&a,WUNTRACED);


                      tcsetpgrp(STDIN_FILENO,getpgrp());
                      
                      signal(SIGTTIN,SIG_DFL);

                      signal(SIGTTOU,SIG_DFL);

                     if(a>0)
                     {global=-1;}                      

                if(WIFSTOPPED(a))
		{ break;

		}
                else if(flag1==1)
	       {proc[i]=-1;}
	       break;
               		       
            }
    }

if(j!=x)
    {global=-1;printf("NO SUCH JOB nUMBER\n");}

}