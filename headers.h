#ifndef HEADERS_H
#define HEADERS_H

#include<stdio.h>
#include <sys/utsname.h>
#include <unistd.h>
#include<signal.h>
#include <sys/wait.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>
 #include <sys/types.h>
#include <sys/dir.h>
#include<stdlib.h>
#include<pwd.h>
#include<time.h>
#include<grp.h>
#include<fcntl.h>
#include<sys/uio.h>
#include<math.h>
char *home;
void cd(char **comm);
void echoes(char **comm);
void ls(char **comm);
void cwd(char **comm);
void runcomm(char **comm, char histor[22][1024],int proc[],int *sze,char *procname[1000]);
char **indicommand(char *b);
char **commands(char *enter,long long a,long long *b);
void prompt(int a , int *fd,int *hno,char histor[22][1024],int proc[],int *sze,char *procname[1000]);
char *permi(mode_t mode);
void pinfo(char **comm);
void nightswatch(char **comm);
int mina(int a,int b);
int main();
void quit(char **comm,int proc[]);
void signalhandler(int sig);
void manage(char **comm,int proc[],int *sze,char *procname[1000]);
void pipes(char **comm);
void IO(char **comm);
void unset(char ** comm);
void envset(char **comm);
void overkill(int proc[1000]);

void histo(char **comm,char hist[22][1024]);
int global=0;


#endif

