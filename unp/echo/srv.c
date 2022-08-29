#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

void str_echo(int connfd);

typedef void SigFunc(int);
void sig_chld(int signo);

int main() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    struct sockaddr_in srvaddr;
    memset(&srvaddr, 0, sizeof(srvaddr));
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(59999);
    srvaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int rst;
    if ((rst = bind(sockfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr))) < 0) {
        perror("bind error");
        exit(1);
    }

    SigFunc *sigFunc = signal(SIGCHLD, &sig_chld);
    if (sigFunc == SIG_ERR) {
        perror("signal error");
        exit(1);
    }

    if ((rst = listen(sockfd, 8)) < 0) {
        perror("listen error");
        exit(1);
    }

    int connfd;
    int pid;
    while (1) {
        if ((connfd = accept(sockfd, NULL, NULL)) < 0) {
            perror("accept error");
            exit(1);
        }

        if ((pid = fork()) == 0) {
            close(sockfd);
            str_echo(connfd);
            close(connfd);
            exit(0);
        }

        close(connfd);
    }
    return 0;
}

void str_echo(int connfd) {
    char s[100];
    int n;
    while ((n = read(connfd, s, 100)) > 0) {
        printf("receive: %s", s);
        write(connfd, s, strlen(s));
    }
}

void sig_chld(int signo) {
    int stat;
    pid_t pid;
    // pid = wait(&stat);
    // printf("child %d terminated\n", pid);
    while ((pid = waitpid(-1, &stat, WNOHANG)) > 0) {
        printf("child %d terminated\n", pid);
    }
    return;
}