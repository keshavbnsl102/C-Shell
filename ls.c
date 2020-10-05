#include "headers.h"
char* permi(mode_t mode)
{
   char * stri=(char *)malloc(12);
   int i = 0;
    if (S_ISDIR(mode))
     {stri[i] = 'd';
        i++;
       }
    else {
        stri[i] = '-';
        i++;
        }
    
    if ((mode & S_IRUSR) == S_IRUSR) 
    {stri[i] = 'r';
        i++;
    }
    else 
    {stri[i] = '-';
        i++;
    }
    if ((mode & S_IWUSR) == S_IWUSR) 
    { stri[i] = 'w';
        i++;
    }
    else {
        stri[i] = '-';
        i++;
    }
    if ((mode & S_IXUSR) == S_IXUSR) 
    {stri[i] = 'x';
        i++;
    }
    else {
        stri[i] = '-';
        i++;
    }
    if ((mode & S_IRGRP) == S_IRGRP) 
    { stri[i] = 'r';
        i++;
    }
    else {
        stri[i] = '-';
        i++;
    }

    if ((mode & S_IWGRP) == S_IWGRP) 
    {stri[i] = 'w';
        i++;
       }
    else {
        stri[i] = '-';
        i++;
        }
    if ((mode & S_IXGRP) == S_IXGRP) 
    {stri[i] = 'x';
        i++;
        }
    else {
        stri[i] = '-';
        i++;
        }
    if ((mode & S_IROTH) == S_IROTH) 
    {stri[i] = 'r';
        i++;
         }
    else {
        stri[i] = '-';
        i++;
        }
    if ((mode & S_IWOTH) == S_IWOTH) 
    {stri[i] = 'w';
        i++;
         }
    else {
        stri[i] = '-';
        i++;
        }
    if ((mode & S_IXOTH) == S_IXOTH) 
    {stri[i] = 'x';
        i++;
        }
    else {
        stri[i] = '-';
        i++;
         }
         stri[i]='\0';
    return stri;
}

void ls(char **comm)
{   int f=0;
   if(comm[1]==NULL)
   {  f=1;}
   char** yes=(char **)malloc(1000*sizeof(char *));
   int fl,fa;
   fl=0;fa=0;
   int i=0,j=0,count=0;
   int arr[1024];
   for(i=1;comm[i]!=NULL;i++)
   {   arr[i]=0; 
       if(strcmp(comm[i],"-l")==0)
       {fl=1;}
       else if(strcmp(comm[i],"-a")==0)
       {fa=1;}
       else if(strcmp(comm[i],"-la")==0)
       {fl=1;fa=1;}
       else if(strcmp(comm[i],"-al")==0)
       {fl=1;fa=1;}
        else
        {
            arr[i]=1;
            count++;
         }


     }
     //printf("%d %d\n",i,count);
   for(j=1;(j<i||count==0);j++)
   {      struct dirent *stfu;
        printf("\n");

       if(count==0)
         {goto flaggy;}
      if(arr[j]==0)
      {continue;}
      else
      {   flaggy:; 
          
          char *paths=(char *)malloc(1024*sizeof(char));
           if(count==0)
           {goto poop;}
          if(comm[j][0]=='~')
          { 
              paths=home;
              int l=1;
              int k;
              for( k=strlen(home);l<strlen(comm[j]);k++)
              {  paths[k]=comm[j][l];
                 l++;
               }
               paths[k]='\0';
          }
          else 
          {paths=comm[j];}
        
          poop:;
          if(count==0)
          {getcwd(paths,1000);}
            
           
             DIR *dir=opendir(paths);
             if(dir==NULL)
             { printf("couldn't open %s:\n",comm[j]);global=-1;continue;}
             if(fl==1)
             {
                            while((stfu=readdir(dir))!=NULL)
                {       
                        struct stat st;
                        char yehi[1024];yehi[0]='\0';
                        strcat(yehi,paths);
                        strcat(yehi,"/");
                        strcat(yehi,stfu->d_name);
                        stat(yehi,&st);
                        if(stfu->d_name[0] == '.') 
                        {   if(fa==0)
                            {continue;}
                        }
                        printf("  %s ",permi(st.st_mode) );

                        printf(" %lu ",st.st_nlink );
                        struct passwd *password;
                        struct group * grp;
                        if ((password = getpwuid(st.st_uid)) != NULL)
                        {
                            printf(" %s", password->pw_name);
                        }
                        if ((grp=getgrgid(st.st_gid))!=NULL) 
                        {   
                           printf(" %s ", grp->gr_name);
                         }
                
                        printf("  %ld ", st.st_size);
                        struct tm* tms = localtime(&st.st_mtime);
                        char dates[1000];
                        strftime(dates, sizeof(dates), "%b %d %H:%M", tms);
                        printf(" %s %s\n", dates, stfu->d_name);



             }

           
           }
           else if(fa==1)
           {   while((stfu=readdir(dir))!=NULL)
                {  //stfu=readdir(dir);
                    printf("%s\n",stfu->d_name);
                }



           }
           else
           {  //printf("YAY\n");
             int x=0;
               while((stfu=readdir(dir))!=NULL)
                {   //printf("%d",x);
                   if(stfu->d_name[0]=='.'){continue;}
                    printf("%s\n",stfu->d_name);
                    x++;
                }
               
           }
           closedir(dir);
           
           

     if(count==0)
     {break;}
   }

}
}