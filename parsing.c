#include "headers.h"

char **indicommand(char *b)
{
  char **parsed2;
   parsed2=(char **)malloc(1000*sizeof(char *));
   char *oneatatime=strtok(b,"\n ");
   int cnumber=0;
   while(oneatatime!=NULL)
   {    
        parsed2[cnumber]=oneatatime;
        cnumber++;
       oneatatime=strtok(NULL,"\n\t ");
   }
   parsed2[cnumber]=NULL;
   return parsed2;
    
}


char **commands(char *enter,long long a,long long *b)
{
   char **parsed1;
   parsed1=(char **)malloc(a*sizeof(char *));
   char *oneatatime=strtok(enter,";");
   int cnumber=0;
   while(oneatatime!=NULL)
   {    
        parsed1[cnumber]=oneatatime;
        cnumber++;
       oneatatime=strtok(NULL,";");
   }
   *b=cnumber;
   parsed1[cnumber]=NULL;
   return parsed1;


}
