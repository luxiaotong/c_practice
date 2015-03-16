#include "my_sock.h"

void clean_zombie(int signum)
{
    int pid, stat;
    pid = wait(&stat);
    printf("clean zombie: %d\n", pid);
    return;
}

int main(int argc, char *argv[])
{
    int sockfd, listenfd, connfd;
    int bind_rtn, accept_rtn;
    int backlog = 5;
    int pid;
    int write_rtn, read_rtn;
    struct sockaddr_in servaddr, cliaddr;

    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(23456);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( sockfd < 0 ) perror("socket fail");

    bind_rtn = bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if ( bind_rtn < 0 ) perror("bind fail");

    connfd  = listen(sockfd, backlog);
    if ( connfd < 0 ) perror("listen fail");

    signal(SIGCHLD, clean_zombie);

    for(;;){
        connfd = accept(sockfd, NULL, 0);
        if ( connfd < 0 ) {
            if ( errno == EINTR ) {
                continue;
            } else {
                perror("accept fail");
            }
        }

        if ( (pid = fork()) == 0 ) {
            close(sockfd);

            char get_str[20];
            while ( ( read_rtn = read(connfd, get_str, sizeof(get_str)) ) != 0 ) {
                if ( read_rtn < 0 ) {
                    perror("read fail");
                } else {
                    printf("get: %s", get_str);
                    write(connfd, get_str, sizeof(get_str));
                }
                memset(get_str, 0, sizeof(get_str));
            }

            printf("close..%d\n", connfd);
            close(connfd);
            exit(0);
        }

        close(connfd);
    }
    
    close(sockfd);

    return 0;
}
