#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include<fcntl.h> 
#include<pthread.h>
int arr[1000000];
/*void parse(char *buffer , char **argv1)
{
    while (*buffer!='\0')
    {
        while(*buffer == ' ' || *buffer == '\t' || *buffer == '\n')
        {
            *buffer++ = '\0';
        }
        *argv1++ = buffer;
        while(*buffer != '\0' && *buffer !=' ' && *buffer != '\t' && *buffer !='\n')
        buffer++;
    }
    *argv1 = '\0';
}*/
void Die(char *mess) 
{
    perror(mess);
    exit(1);
}
int j=1;
void execute(char **argv1)
{
    pid_t  pid;
    int    status;
    int pipefd[2],lenght;
    if(pipe(pipefd))
        Die("Failed to create pipe");
    if ((pid=fork()) < 0) 
    {     // fork a child process           
        printf("*** ERROR: forking child process failed\n");
        exit(1);
    }
    else if(pid == 0)
    {
        
        /*if(send(newsockfd, &j, sizeof(j), 0)<0)
          {
              Die("sorry !");
          }*/
        /*if(execvp(*argv1,argv1)<0)
        {
            printf("***ERROR***\n");
            exit(1);
        }*/
        //close(1);
        /*dup2(pipefd[1],1);
        close(pipefd[0]); // close the readonly side of the pipe
        close(pipefd[1]); // close the original write side of the pipe
        execvp(argv1[0],argv1); // finally execute the command*/
        arr[j]=getpid();
        j++;
        while(1)
        {
        int newfd = open("serverclient.txt",O_WRONLY | O_APPEND | O_CREAT , 0644); 
        // here the newfd is the file descriptor of stdout (i.e. 1) 
        dup2(newfd, 1) ;
        execvp(argv1[0],argv1);
        }
    }
    /*else
    {
        while(wait(&status) !=pid);
    }*/  
}
void error(const char *msg)
{
    perror(msg);
    exit(1);
}
int main()
{
    char *argv1[64];
    //parse(argv1);       //   parse the line               
          if (strcmp(argv1[0], "exit") == 0)  // is it an "exit"?     
               exit(0); 
    execute(argv1); 
}