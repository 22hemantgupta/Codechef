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
void parse(char *buffer , char **argv1)
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
}
void Die(char *mess) 
{
    perror(mess);
    exit(1);
}
int j=1;
/*void execute(char **argv1)
{
    
}*/
void error(const char *msg)
{
    perror(msg);
    exit(1);
}
int main()
{
    char *argv1[64];
    char buffer[256];

     gets(buffer);
     pid_t  pid;
     parse(buffer,argv1);       //   parse the line               
          if (strcmp(argv1[0], "exit") == 0)  // is it an "exit"?     
               exit(0); 
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
        /*int newfd = open("serverclient.txt",O_WRONLY | O_APPEND | O_CREAT , 0644); 
        // here the newfd is the file descriptor of stdout (i.e. 1) 
        dup2(newfd, 1) ;*/
        pid_t pid1;
        if ((pid1=fork()) < 0) 
        {     // fork a child process           
        printf("*** ERROR: forking child process failed\n");
        exit(1);
        }
        else if(pid1 == 0)
        {
        execvp(argv1[0],argv1);
        }
        else
        {
        while(wait(&status) !=pid1);
        }
        }
    }
    else
    {
        while(wait(&status) !=pid);
    }
    return 0; 
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include<fcntl.h> 
#include<signal.h>
#include<pthread.h>
int sockfd, newsockfd, portno;
int arr[1000000];
/*void *connection_handler(void *arv)
{
    char **argv2=(char**)arv;
    while(1)
        {
        int newfd = open("mysercli.txt",O_WRONLY | O_APPEND | O_CREAT , 0644); 
        // here the newfd is the file descriptor of stdout (i.e. 1) 
        dup2(newfd, 1) ;
        execvp(argv2[0],argv2);
        }
}*/
void parse(char *buffer , char **argv1)
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
}
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
        if(send(newsockfd, &j, sizeof(j), 0)<0)
          {
              Die("sorry !");
          }
        arr[j]=getpid();
        j++;
        while(1)
        {
           // pid_t pid1;
           // int status1;
            if ((pid=fork()) < 0) 
        {     // fork a child process           
        printf("*** ERROR: forking child process failed\n");
        exit(1);
        }
        else if(pid == 0)
        {
        int newfd = open("serverclient1.txt",O_WRONLY | O_APPEND | O_CREAT , 0644); 
        // here the newfd is the file descriptor of stdout (i.e. 1) 
        dup2(newfd, 1) ;
        execvp(argv1[0],argv1);
        }
        else
        {
            while(wait(&status) !=pid);
        }
        }
    }
    /*else
    {
        while(wait(&status) !=pid);
    } */
}
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
     while(1)
     {
         char *argv1[64];
           bzero(buffer,255);
           n = read(newsockfd,buffer,255);
           if (n < 0) error("ERROR reading from socket");
           printf("Client: %s\n",buffer);
          parse(buffer, argv1);       //   parse the line               
          if (strcmp(argv1[0], "exit") == 0)  // is it an "exit"?     
               exit(0); 
         /* if(strcmp(argint sockfd, newsockfd, portno;v1[0],"kill")==0)
            {
            //itoa(arr[atoi(argv1[1])],argv1[1],10);
            //sprintf(argv1[2], "%d",arr[atoi(argv1[2])]);
            //execvp(argv1[0],argv1);
            kill(arr[atoi(argv1[1])], SIGKILL);
            exit(0);
            }
                   //   exit if it is  
          //int thread =pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) j) 
          /*if(pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) j)<0)
          {
               perror("could not create thread");
               return 1;
          }   
          //arr[j]=thread;
          int pid=j;*/
          /*pthread_t tid;
          int checking;
        checking = pthread_create(&tid, NULL, connection_handler ,(void *) argv1);
        if (checking !=0)
        perror("create Thread");
        //pthread_exit(NULL);
        arr[j]=tid;
        int pid=j;
        bzero(buffer,255);
          if(send(newsockfd, &pid, sizeof(pid), 0)<0)
          {
              error("sorry !");
          } */        
          execute(argv1); 
          //bzero(buffer,255);
          /*fgets(buffer,255,stdin);
          n = write(newsockfd,buffer,strlen(buffer));
           if (n < 0) error("ERROR writing to socket");
           int i=strncmp("Bye" , buffer, 3);
           if(i == 0)
               break;*/
     }
     //pthread_exit(NULL);
     close(newsockfd);
     close(sockfd);
     return 0; 
}






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include<fcntl.h> 
#include<pthread.h>
void parse(char *buffer , char **argv1)
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
}
void Die(char *mess) 
{
    perror(mess);
    exit(1);
}
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
        while(1)
        {
        int newfd = open("mysercli.txt",O_WRONLY | O_APPEND | O_CREAT , 0644); 
        // here the newfd is the file descriptor of stdout (i.e. 1) 
        dup2(newfd, 1) ;
        execvp(argv1[0],argv1);
        }
    }
    else
    {
        while(wait(&status) !=pid)
        ;
    }  
}
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];
     char *argv1[64];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
     while(1)
     {
           bzero(buffer,255);
           n = read(newsockfd,buffer,255);
           if (n < 0) error("ERROR reading from socket");
           printf("Client: %s\n",buffer);
          parse(buffer, argv1);       //   parse the line               
          if (strcmp(argv1[0], "exit") == 0)  // is it an "exit"?     
               exit(0);            //   exit if it is                
          execute(argv1); 
          //bzero(buffer,255);
          /*fgets(buffer,255,stdin);
          n = write(newsockfd,buffer,strlen(buffer));
           if (n < 0) error("ERROR writing to socket");
           int i=strncmp("Bye" , buffer, 3);
           if(i == 0)
               break;*/
     }
     close(newsockfd);
     close(sockfd);
     return 0; 
}







// client
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
void parse(char *buffer , char **argv1)
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
}
void  execute(char **argv1)
{
    pid_t  pid;
    int    status;

    if ((pid = fork()) < 0) 
    {     /* fork a child process           */
        printf("*** ERROR: forking child process failed\n");
        exit(1);
    }
    else if(pid == 0)
    {
        if(execvp(*argv1,argv1)<0)
        {
            printf("***ERROR***\n");
            exit(1);
        }
    }
    else
    {
        while(wait(&status) !=pid)
        ;
    }  
}
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    char *argv1[64];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    while(1)
    {
        printf("Client: ");
        bzero(buffer,255);
        gets(buffer);
       // parse(buffer, argv1);       /*   parse the line               */
       // if (strcmp(argv1[0], "exit") == 0)  /* is it an "exit"?     */
       //    exit(0);            /*   exit if it is                */
       // execute(argv1); 
        n = write(sockfd,buffer,strlen(buffer));
        if(strcmp(buffer,"exit")==0)
        {
            exit(0);
        }
        if (n < 0) 
             error("ERROR writing to socket");
        /*bzero(buffer,256);
        n = read(sockfd,buffer,255);
        if (n < 0) 
             error("ERROR reading from socket");
        printf("Server : %s\n",buffer);
        int i = strncmp("Bye" , buffer , 3);
        if(i == 0)
               break;*/
    }
    close(sockfd);
    return 0;
}