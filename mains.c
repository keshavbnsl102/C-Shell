#include "headers.h"
#include "functions.c"
void sigi(int sig)
{ 
	printf("ctrlc pressed\n");
  	return;
}
int proc[1000];
   char *procname[1000];

void handler(int sig)
{
            int status;
        pid_t ver=waitpid(-1,&status,WNOHANG);
            if(ver>0)
            {
                    if(!WIFEXITED(status))
                    {for(int i=0;i<1000;i++)
                            {if(proc[i]==ver)
                                    {
                       printf("\nABNORMAL:process with name %s and pid %d exited abnormally with status:%d\n",procname[i],ver,WEXITSTATUS(status));
                       proc[i]=-1;
                     procname[i]=NULL;
                    }


                     }

                    }

              }
            for(int i=0;i<1000;i++)
            {  if(proc[i]>0)
            {if(kill(proc[i],0)==-1)
                    {printf("\nNORMAL EXIT: process with name %s and pid %d exited normally\n",procname[i],proc[i]);
                procname[i]=NULL;
                            proc[i]=-1;}
             }
            }



}

int main()
{   
    home=getcwd(home,1000);
    char hist[22][1024];
   int a=0;
   int fd;
   int hno;
   
   for(int i=0;i<1000;i++){proc[i]=-1;}
     int sze=0;
    while(1)
    {    
            signal(SIGINT,sigi);
             signal(SIGCHLD,handler);            

	    prompt(a,&fd,&hno,hist,proc,&sze,procname);
        a++;

    }
    
return 0;

}
