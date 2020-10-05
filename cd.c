#include "headers.h"

int chadi=0;
char paths[1024];
void cd(char **comm)
{    int x=0;
     global=1;
     	
    if(comm[1]==NULL)
    {      int i=0;
	    getcwd(paths,1000);
          chdir(home);
	  return;
	 

    }
    if(comm[1][0]=='-')
    {   
	    int i;
	    char *paths2=(char *)malloc(1000);
	    for(i=0;i<strlen(paths);i++)
	    {paths2[i]=paths[i];}
	    paths2[i]='\0';
	    getcwd(paths,1000);
	if(chadi==0)
	{printf("%s\n",home);
	  getcwd(paths,1000);	
	}	
         else
	 {
	   	 
           printf("%s\n",paths2);
           chdir(paths2);	   

	 }		 


    }
    else if(comm[1][0]=='~')
    {        char paths2[1000];
	    getcwd(paths2,1000);
	   char yes[1000];
         int i=0,j;
         for( i=0;i<strlen(home);i++)
         {yes[i]=home[i];}
         for(j=1;j<strlen(comm[1]);j++)
         {
             yes[i]=comm[1][j];
             i++;
         }
         yes[i]='\0';
        x=chdir(yes);
	if(x>=0)
	{for(i=0;i<strlen(paths2);i++)
		{paths[i]=paths2[i];}
		paths[i]='\0';
	}

    }
    else{
	    int i;
	 char paths2[1000];
            getcwd(paths2,1000);

         x=chdir(comm[1]);
	 if(x>=0)
        {for(i=0;i<strlen(paths2);i++)
                {paths[i]=paths2[i];}
                paths[i]='\0';
        }


    }
    if(x<0)
    {global=-1;perror("directory not found");return;}
    if(chadi==0)
    {chadi=1;}


}
