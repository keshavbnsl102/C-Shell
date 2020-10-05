#include "headers.h"

void nightswatch(char **comm)
{     
	if(comm[1]==NULL||comm[2]==NULL||comm[3]==NULL)
	{global=-1;printf("ERROR: MORE ARGUMENTS REQUIRED\n");return;}

   if(comm[4]!=NULL)
   {global=-1;printf("error:: too many ARGUMENTS;\n");return;}
   int arg=atoi(comm[2]);
  if(strcmp(comm[1],"-n")!=0||arg==0||strcmp(comm[3],"interrupt")!=0)
    { global=-1;printf("ERROR: INVALID COMMAND\n");return;}
   
  FILE *f1;
   f1=fopen("/proc/interrupts","r");
   int f=0;
  if(f1==NULL)
  {global=-1;perror("fopen");return; }
   char *yes;
    size_t buf;
     char *enter=(char *)malloc(1024);
posi:;
    
     fd_set SET_1;
     struct timeval ti;
     ti.tv_sec=0;
     ti.tv_usec=0;
     int val;
     FD_ZERO(&SET_1);FD_SET(0,&SET_1);
     val=select(1,&SET_1,NULL,NULL,&ti);
     if(val==-1)
     {global=-1;perror("select()");}
     else if(val)
     {
	     val=select(1,&SET_1,NULL,NULL,&ti);
	     char a=fgetc(stdin);
	     char b=fgetc(stdin);
	     if(a=='q')
	     {return ;}
     }

     fseek(f1,0L,SEEK_SET);

     if(f==0)
     {getline(&enter,&buf,f1);
      printf("%s",enter);}
      f=1;
      char tobe[1024];
   while(getline(&enter,&buf,f1)!=-1)
   {   int x=strlen(enter);
	if(x<5){continue;}
         for(int i=0;i<x-4;i++)
	 {
		 if(enter[i]=='i'&&enter[i+1]=='8'&&enter[i+2]=='0'&&enter[i+3]=='4'&&enter[i+4]=='2')
	     {    int j=0;
		     for( j=0;j<x;j++)
	       {tobe[j]=enter[j];
	                           }
	         tobe[j]='\0';
	          break;
              }	     
   
            }
   }
   for(int i=0;i<strlen(tobe);i++)
   {if(tobe[i]=='I'){tobe[i]='\0';break;}}
	 printf("%s\n",tobe);
   sleep(arg);
    goto posi;
   fclose(f1);





}	
