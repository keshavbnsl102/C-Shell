#include "headers.h"

void pipes(char **comm)
{
    int i,j,k,endfl,m,pehla,doosra;
    char **pi=(char **)malloc(1000*sizeof(char*));
    j=0;m=0;
    endfl=0;
    int fd[2];
    
    while(1)
    {    
        k=0;
        
        while(1)
        {
            if(comm[j]==NULL)
            {endfl=1;
              break;
            } 
            else if(!strcmp(comm[j],"|"))
            {break;}
            else
            {
                pi[k]=comm[j];
            }
            k++;
            j++;


        }
           pi[k]=NULL;
           m++;
           j++;
           global=1;
          if(m==1)
          {  i=0;
              char *inp=(char *)malloc(1000);
              pipe(fd);
              int mask=0;
              while(pi[i]!=NULL)
              {
                  if(!strcmp(pi[i],"<"))
                  {pi[i]=NULL;
                    mask=1;
                    if(pi[i+1]==NULL)
                    {global=-1;printf("wrong command\n");continue;}
                     strcpy(inp,pi[i+1]);
                  
                  }
                  i++;
              }
              if(mask==1)
              {   int fdi=open(inp,O_RDONLY,0644);
                  if(fdi<0)
                  {global=-1;printf("couldn't open input file\n"); }
                    pehla=dup(0);
                   dup2(fdi,0);
              }
              doosra=dup(1);
              dup2(fd[1],1);
              close(fd[1]);

          }
          else if(endfl==0)
          {
              pehla=dup(0);
              dup2(fd[0],0);
              pipe(fd);
              doosra=dup(1);
              dup2(fd[1],1);
              close(fd[1]);
           }
          else
          {
              i=0;
              char *out=(char *)malloc(1000);
              int app=0;
              int mask=0;
              while(pi[i]!=NULL)
              {
                  if(!strcmp(pi[i],">"))
                   { pi[i]=NULL;
                     mask=1;
                     app=0;
                     if(pi[i+1]==NULL)
                     {global=-1;printf("ERROR: WRONG COMMAND\n");continue;}
                       strcpy(out,pi[i+1]);
                    }
                   else if(!strcmp(pi[i],">>"))
                   {app=1;
                     mask=1;
                       if(pi[i+1]==NULL)
                     {global=-1;printf("ERROR: WRONG COMMAND\n");continue;}
                     strcpy(out,pi[i+1]);


                   } 
                   i++;
              }
                if(mask==1)
              {     int fdo;
                if(app==1)
                {
                    fdo=open(out,O_WRONLY|O_CREAT|O_APPEND,0644);
                    if(fdo<0)
                    {global=-1;perror("OUTPUT FILE ERROR\n");}
                    doosra=dup(1);
                    dup2(fdo,1);

                }
                else
                {fdo=open(out,O_WRONLY|O_CREAT|O_TRUNC,0644);
                  if(fdo<0)
                    {global=-1;perror("OUTPUT FILE ERROR\n");}
                    doosra=dup(1);
                    dup2(fdo,1);


                  }
              }
                  pehla=dup(0);
                  dup2(fd[0],0);
                  close(fd[0]);

          }
   

      int ekpip[2];ekpip[0]=0;ekpip[1]=0;pipe(ekpip); pid_t pid=fork();
     if(pid<0)
     {global=-1;perror("error while forking:\n");}
     else if(pid==0)
     {
         if(execvp(pi[0],pi)==-1)
         {   int a=-1;
             close(ekpip[0]);
             write(ekpip[1],&a,sizeof(&a));
             close(ekpip[1]);
             perror("wrong command\n");
             exit(EXIT_FAILURE);
         }
    }
    else
    {   int statu;
        waitpid(pid,&statu,WUNTRACED);
        if(statu>0)
        {global=-1;}
        close(ekpip[1]);
        read(ekpip[0],&global,sizeof(&global));
        close(ekpip[0]);
        dup2(pehla,0);
        dup2(doosra,1);
        //printf("YES\n");
    }

      if(endfl==1)
      {
          break;
      }

    }
    
}
