#include "headers.h"

void envset(char **comm)
{  global=1;
   if(comm[1]==NULL||comm[3]!=NULL)
     {   global=-1;
         printf("INVALID usage of command\n");
         return;
     }
     if(comm[2]==NULL)
     {comm[2]="";}
     int a=setenv(comm[1],comm[2],1);
     if(a<0)
     {global=-1;printf("command setenv failed to execute\n");}


}
void unset(char ** comm)
{   global=1;
    if(comm[1]==NULL||comm[2]!=NULL)
     {    global=-1;
         printf("INVALID usage of command\n");
         return;
     }
     int a=unsetenv(comm[1]);
     if(a<0)
     {global=-1;printf("command unsetenv failed to execute\n");}


}