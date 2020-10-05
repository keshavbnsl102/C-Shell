#include"headers.h"


void job(char **comm, int proc[1000],char *procname[1000])
{   global=1;
   if(comm[1]!=NULL)
   {global=-1;printf("invalid usage\n");return;}
   char path[1000];
   int i=0;
   int x=0;
   for(i=0;i<1000;i++)
   {
	   if(proc[i]<=0)
	   {continue;}
	   x++;
	   int pid=proc[i];

            strcpy(path,"/proc/");
	    char num[10];
	    sprintf(num,"%d",pid);
	    strcat(path,num);
	    strcat(path,"/status");
          FILE *fd=fopen(path,"r");
	  char *str1;
	  char *str2;
	  char *str3;
	   size_t a,b,c;
           getline(&str1,&a,fd);
	   getline(&str2,&b,fd);
	    getline(&str3,&c,fd);

	   int j=0,f=0;
	   char ch;

	   printf("[%d.] ",x);
	   
	   for(j=0;j<100;j++)
	   {
		if(str3[j]=='e')
		{f=1;continue;}
		if(f==1&&str3[j]!=' '&&str3[j-1]=='\t')
		{ch=str3[j];break;}
           }
	   
	   printf("%c ",ch);
	   if(ch=='R'||ch=='S')
	   { printf("RUNNING ");}
	    else 
            {printf("STOPPED ");}
          printf("%s ",procname[i]);
	  printf("[%d]\n",pid);


    }

   
       
 }

void kjobs(char **comm,int proc[],char *procname[1000])
{  global=1;
   if(comm[1]==NULL||comm[2]==NULL)
   { global=-1;printf("INVALID USAGE OF cOmmand\n");return;}
   int i,j,k;
   for(i=0;comm[1][i]!='\0';i++)
   { if(comm[1][i]<48||comm[1][i]>57)
	   {global=-1;printf("INVALID COMMAND\n");return;}
   }
   for(i=0;comm[2][i]!='\0';i++)
   {if(comm[2][i]<48||comm[2][i]>57)
	   {global=-1;printf("INVALID COMMAND\n");return;}
   }
   int x=atoi(comm[1]);
   int y=atoi(comm[2]);
   if(y<0||y>9)
   {global=-1;printf("INVALID SIGNAL\n");return;}
   j=0;
   int f=0;
   for(i=0;i<1000;i++)
   {
	   if(proc[i]<=0)
	   {continue;}
          j++;
          if(j==x)
	  {    f=1;
		 int m= kill(proc[i],y);
		  if(m<0)
		  {global=-1;printf("WRONG SIGNAL NUMBER\n");}
		 break;

	  }
		  

   }
   if(f==0)
   {global=-1;printf("INVALID JOB NUMBER\n");return;}





}	
void overkill(int proc[])
{  global=1;
   for(int i=0;i<1000;i++)
   {
	   if(proc[i]>0)
	   {kill(proc[i],9);
	     
	    }
   }




}