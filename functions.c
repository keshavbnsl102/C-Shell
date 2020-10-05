#include "headers.h"
#include "cd.c"
#include "history.c"
#include "ls.c"
#include "nightswatch.c"
#include "parsing.c"
#include "pinfo.c"
#include "prompt.c"
#include "piping.c"
#include "redirect.c"
#include "bonus3.c"
#include "set&unset.c"
#include "jobs.c"
#include "fg.c"
#include "bg.c"





void echoes(char **comm)
{   global=1;
    for(int i=1;comm[i]!=NULL;i++)
    {printf("%s ",comm[i]);}
    printf("\n");


}

void cwd(char **comm)
{     global=1;
    char yay[1005];getcwd(yay,1000);
    printf("%s\n",yay);
}


int af=0;
int fpid;
void signalhandler(int sig)
{     kill(fpid,SIGTSTP);
	af=1;	
}	
void ctrlc(int sig)
{
	kill(fpid,9);
}
 	
void manage(char **comm,int proc[],int *sze,char *procname[1000])
{    global=1;
      af=0;
      int flagforbackg=0;
      char *news[1024]={NULL};

      for(int i=0;comm[i]!=NULL;i++)
      { if(strcmp(comm[i],"&")==0)
	      {flagforbackg=1;break;}
	      news[i]=comm[i];
       }
       
      if(flagforbackg==0)
      {   int ekaurpip[2];
            ekaurpip[0]=0;
            ekaurpip[1]=0;
            pipe(ekaurpip);
          int pid=fork();
	      if(pid==0)
	      {      setpgid(0,0);
		      
		      if(execvp(news[0],news)<0)
              {
            
                    int b=-1;
                  write(ekaurpip[1],&b,sizeof(&b));
                 close(ekaurpip[1]);
               printf("ERROR: wrong command\n");exit(0);}
	      }
	      else{
		      fpid=pid;
		      int ye;

		     
                          
		      tcsetpgrp(STDIN_FILENO,pid);

		      signal(SIGTTIN,SIG_IGN);


		      signal(SIGTTOU,SIG_IGN);
              //signal(SIGTSTP,signalhandler);

		      waitpid(pid,&ye,WUNTRACED);
              // printf("%d\n",ye);


		      tcsetpgrp(STDIN_FILENO,getpgrp());

		      signal(SIGTTIN,SIG_DFL);

              
		      signal(SIGTTOU,SIG_DFL);
              
             

		      if(WIFSTOPPED(ye))
		      {proc[*sze]=pid;
                procname[*sze]=comm[0];
			      af=0;
			      *sze=*sze+1;
                  global=-1;
                  return;
		      }    
                 close(ekaurpip[1]);
                read(ekaurpip[0],&global,sizeof(&global));
                 close(ekaurpip[0]);
             
                if(ye>0)
             {global=-1;}  
	           
          }
	      
	      
	      
	  }
      else
      {int pi=fork();
          if(pi>0)
          {procname[*sze]=comm[0];
            proc[*sze]=pi;
	    *sze=*sze+1;
          }
	     
          
	      
	      if(pi==0)
	      {       setpgid(0,0);
		      execvp(news[0],news);
              
		      printf("\nERROR:WRONG COMMAND\n");exit(0);
		     
	      }
      }


    



}

void quit(char **comm,int proc[])
{ int pid=getpid();
	overkill(proc);
	kill(pid,SIGQUIT);
}











void runcomm(char **comm,char historries[22][1024],int two[],int *sze,char *procname[1000])
{    global=1;
    if(comm[0]==NULL)
    {return ;}
    int i=0;
    int piping=0;
    int redir=0;
    int dollar=0;
    while(comm[i]!=0)
    {
         if((!(strcmp(comm[i],"$")))||(!(strcmp(comm[i],"@"))))
        {dollar=1;}
        
         i++;

    }
    i=0;
    while(comm[i]!=NULL)
    {
        if(!(strcmp(comm[i],"|")))
        {piping=1;}
        if((!strcmp(comm[i],">"))||(!strcmp(comm[i],"<"))||(!strcmp(comm[i],">>")))
        {redir=1;}
        i++;
     }
     if(dollar==1)
     {
         bonus3(comm,historries,two,sze,procname);
         return;
     }
     if(piping==1)
     {
         pipes(comm);
         return;
     }
     if(redir==1)
     {
         IO(comm);
         return;

     }


    if(strcmp(comm[0],"echo")==0)
   {
         echoes(comm);

   }
   else if(strcmp(comm[0],"cwd")==0)
   {  cwd(comm);
      
   }
    else if(strcmp(comm[0],"cd")==0)
    {
        cd(comm);
    }
    else if (strcmp(comm[0],"ls")==0)
    {
         ls(comm);

    }
    else if(strcmp(comm[0],"history")==0)
    {histo(comm,historries);}
    else if(strcmp(comm[0],"quit")==0)
    {quit(comm,two);}
    else if(strcmp(comm[0],"pinfo")==0)
    {pinfo(comm);}
    else if(strcmp(comm[0],"nightswatch")==0)
    {nightswatch(comm);}
    else if(strcmp(comm[0],"setenv")==0)
    {envset(comm);}
    else if(strcmp(comm[0],"unsetenv")==0)
    {unset(comm);}
    else if(strcmp(comm[0],"jobs")==0)
    {job(comm,two,procname);}
    else if(strcmp(comm[0],"kjob")==0)
    {kjobs(comm,two,procname);}
    else if(strcmp(comm[0],"fg")==0)
    {fg(comm,two,procname,sze);}
    else if(strcmp(comm[0],"bg")==0)
    {bg(comm,two,procname);}
    else if(strcmp(comm[0],"overkill")==0)
    {overkill(two);}
    else
   { manage(comm,two,sze,procname);}
   
    


}


 
