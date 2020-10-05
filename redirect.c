#include "headers.h"

void IO(char **comm)
{
    int append=0,greater=0,less=0;
     int i=0;
     char inp[1024];
     char out[1024];
     int fl=0;
     int pehla,doosra;
     for(i=0;comm[i]!=NULL;i++)
     { 
         if(!strcmp(comm[i],">"))
         {greater=1;
         fl=0;
           comm[i]=NULL;
             if(comm[i+1]==NULL)
              {global=-1;printf("error: wrong command\n");return;}
              else
              {strcpy(out,comm[i+1]);}
         }
         else if(!strcmp(comm[i],"<"))
         {less=1;
           comm[i]=NULL;
             if(comm[i+1]==NULL)
              {global=-1;printf("error: wrong command\n");return;}
              else
              {strcpy(inp,comm[i+1]);}
         
         }
         else if(!strcmp(comm[i],">>"))
         {append=1;
            comm[i]=NULL;
            fl=1;
             if(comm[i+1]==NULL)
              {global=-1;printf("error: wrong command\n");return;}
              else
              {strcpy(out,comm[i+1]);}
         
         
         
         }
    }
    if(less==1)
    {
        int fd=open(inp,O_RDONLY,0644);
        if(fd<0)
        {global=-1;perror("error:\n"); return;    }
        pehla=dup(0);
        dup2(fd,0);


    }
    if(greater==1||append==1)
     {  
         if(fl==1)
         {
             int fd2=open(out,O_WRONLY|O_CREAT|O_APPEND,0644);
             if(fd2<0){global=-1;perror("couldn't open file\n");return;}
            doosra=dup(1);
            dup2(fd2,1);
 
         }
         else
         { int fd2=open(out,O_WRONLY|O_CREAT|O_TRUNC,0644);
             if(fd2<0){global=-1;perror("couldn't open file\n");return;}
            doosra=dup(1);
            dup2(fd2,1);
         }


     }
     int ppip[2];ppip[0]=0;ppip[1]=0;pipe(ppip); pid_t pid=fork();
     if(pid<0)
     {global=-1;perror("error while forking:\n");return ;}
     else if(pid==0)
     {
         if(execvp(comm[0],comm)==-1)
         {    int a=-1;
              close(ppip[0]);
              write(ppip[1],&a,sizeof(&a));
              close(ppip[1]);
              perror("wrong command\n");
             exit(EXIT_FAILURE);
         }
    }
    else
    {  int statu;

        waitpid(pid,&statu,WUNTRACED);
        if(statu>0)
        {global=-1;}
        close(ppip[1]);
        read(ppip[0],&global,sizeof(&global));
        close(ppip[0]);

        dup2(pehla,0);
        dup2(doosra,1);
    }
}