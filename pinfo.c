#include "headers.h"
void pinfo(char ** comm)
{  long int pi;
     if(comm[1]!=NULL)
     { if(comm[2]!=NULL)
	     {global=-1;printf("ERROR: TOO MANY ARGUMENTS\n");return;}
	pi=atoi(comm[1]);
         if(pi==0)
	 {global=-1;printf("ERROR: enter a numeric id\n");return;}	 
      }
      else
      {pi=getpid();}
      char yehi[1024];
       char kyu[1024];
       sprintf(kyu,"%ld",pi);
       sprintf(yehi,"%s","/proc/");
       int len=strlen(yehi);
       int k;
       for(k=len;k<len+strlen(kyu);k++)
       {yehi[k]=kyu[k-len];}
         yehi[k]='\0';

       char yehi2[1024];
       for(k=0;k<strlen(yehi);k++)
            {yehi2[k]=yehi[k];}
           yehi2[k]='\0';
	  
       strcat(yehi2,"/exe");
       strcat(yehi,"/status");
       printf("pid -- %ld\n",pi);
      long long fd;
      fd=open(yehi,O_RDONLY);
      if(fd<0)
       {global=-1;perror("Couldnt open\n");return ;}
       read(fd,yehi,1020);

       int cnt=0;
       char **stor=(char **)malloc(1000*sizeof(char*));
       char *tu;
       tu=strtok(yehi," \n\t  ");
       while(tu!=NULL)
       {stor[cnt]=tu;
	       cnt++;
	     tu=strtok(NULL," \n\t  ");
       }
       for( k=0;k<cnt;k++)
       {     
	       if(strcmp(stor[k],"State:")==0)
	       {printf("Process Status -- {%s}\n",stor[k+1]);}
	       if(strcmp(stor[k],"VmSize:")==0)
	       {printf("memory -- %s   {Virtual memory}\n",stor[k+1]);}
           	       
       }
       printf("Executable Path --  ");
       
       char *does=(char *)malloc(1024);
         int ero=readlink(yehi2,does,1024);
	 if(ero<0)
	 {global=-1;perror("readlink");
	 }
	 else
	 {printf("%s\n",does);}


}