#include "headers.h"

void prompt(int a,int* fd,int* hno,char histor[22][1024],int proc[],int *sze,char *procname[1000]) 
 {   
      if(a==0){
          
      *fd= open("histo.txt",O_RDWR|O_CREAT,0600);
       char buf[1024];
       read(*fd,&buf,1020);
       int ab=0;                                         
        char *yay=strtok(buf,"\n");
        while(yay!=NULL)
        {   int k;
            for( k=0;k<strlen(yay);k++)
             {  histor[ab][k]=yay[k];}
             histor[ab][k]='\0';
            ab++;
            yay=strtok(NULL,"\n");
        }
        *hno=ab;
        close(*fd);
      }

     

     char hname[1000];
     
       gethostname(hname,255); 
      char* uname=getlogin();
      char paths[1000];
       char tobepri[1000];
      
      getcwd(paths,1000);
    
      int i;

      if(strcmp(paths,home)==0)
      {tobepri[0]='~';
        tobepri[1]='\0';
      }
      else if(strlen(paths)<strlen(home))
      {  
          for(i=0;i<strlen(paths);i++)
          {
              tobepri[i]=paths[i];
          }
          tobepri[i]='\0';

      }
      else
      {   int f=0;
         for(i=0;i<strlen(home);i++)
             {
                 if(home[i]!=paths[i])
                 {f=1;}
            }
            if(f==1)
            {for(i=0;i<strlen(paths);i++)
             {
              tobepri[i]=paths[i];
            }
            tobepri[i]='\n';

            }
            else
            {  tobepri[0]='~';
               int j=1;
                for(i=strlen(home);i<strlen(paths);i++)
                { tobepri[j]=paths[i];
                   j++;
                }
                tobepri[j]='\0';

            }
               
           }
           if(global==1)
            {printf("%s",":')");}
            else if(global==-1)
            {printf("%s",":'(");}

      printf("\e[1;93m<%s@%s:%s>\e[0m",uname,hname,tobepri);
      char *enter=(char *)malloc(1024);
       
      size_t buf;
      getline(&enter,&buf,stdin);
      //if(fgets(enter,strlen(enter),stdin)==NULL)
      //{ overkill(proc);
	      //printf("logging out\n");
	     // exit(EXIT_SUCCESS);}
      
      //printf("%s\n",enter);
      if(enter[0]!='\n')
      {

      if(*hno>=20)
      {   
          for(i=0;i<19;i++)
           {  int k;
               for(k=0;k<strlen(histor[i+1]);k++)
               {histor[i][k]=histor[i+1][k];}
               histor[i][k]='\0';

           }
        

           
             for(i=0;i<strlen(enter)-1;i++)
             {
                 histor[19][i]=enter[i];

             }
             histor[19][i]='\0';
         // printf("%s\n",histor[19]);
         // histor[19][strlen(enter)-1]='\0';

      *hno=*hno+1;
      histor[20][0]='\0';


      }
      else
      {   
          for(i=0;i<strlen(enter)-1;i++)
             {
                 histor[*hno][i]=enter[i];

             }

             histor[*hno][i]='\0';
          //histor[*hno][strlen(enter)-1]='\0';
         *hno=*hno+1;
         histor[*hno][0]='\0';

      }
      }

      char yu[1200];
      yu[0]='\0';
      char **aisa;
      aisa=(char **)malloc(1024*sizeof(char*));

      for(i=0;histor[i][0]!='\0';i++)
      {  // histor[i][strlen(histor[i])]='\0';
          aisa[i]=histor[i];
          strcat(yu,aisa[i]);
       strcat(yu,"\n");
      }
      strcat(yu,"\0");
      //printf("%s",yu);
      int fd1;
      fd1=open("histo.txt",O_TRUNC|O_RDWR,0600);
      write(fd1,yu,strlen(yu));
      close(fd1);
       //printf("YES\n");

        long long b=0;
      char **parsed1=commands(enter,buf,&b);
                // printf("%s\n",histor[19]);
            global=1;

      for(int i=0;i<b;i++)
      {              

          char **sepcomm;
                    

          sepcomm=indicommand(parsed1[i]);
            if(i==0&&sepcomm[0]==NULL)
            {global=0;}
          runcomm(sepcomm,histor,proc,sze,procname);
          
      }
     
      
      
 }
