#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

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

    if ((rst = listen(sockfd, 8)) < 0) {
        perror("listen error");
        exit(1);
    }

    int client[FD_SETSIZE];
    for (int i = 0; i < FD_SETSIZE; i++) {
        client[i] = -1;
    }
    fd_set rset, allset;
    FD_ZERO(&allset);
    FD_SET(sockfd, &allset);
    int nfds = sockfd;
    int maxi = -1;
    while (1) {
        rset = allset;
        int nready = select(nfds + 1, &rset, NULL, NULL, NULL);
        if (FD_ISSET(sockfd, &rset)) {
            int connfd = accept(sockfd, NULL, NULL);
            if (connfd < 0) {
                perror("accept error");
                exit(1);
            }
            int i;
            for (i = 0; i < FD_SETSIZE; i++) {
                // printf("client i: %d\n", client[i]);
                if (client[i] < 0) {
                    FD_SET(connfd, &allset);
                    client[i] = connfd;
                    nfds = max(nfds, connfd);
                    maxi = max(maxi, i);
                    // printf("i: %d\n", i);
                    // printf("maxi: %d\n", maxi);
                    printf("connfd: %d\n", connfd);
                    break;
                }
            }
            if (i == FD_SETSIZE) {
                perror("too many clients");
                exit(1);
            }
            if (--nready <= 0) {
                continue;
            }
        }
        for (int i = 0; i <= maxi; i++) {
            if (client[i] < 0) {
                continue;
            }
            int connfd = client[i];
            // printf("connfd in loop: %d\n", connfd);
            if (FD_ISSET(connfd, &rset)) {
                char s[100];
                int n = read(connfd, s, 100);
                if (n > 0) {
                    printf("conn: %d, receive: %s", connfd, s);
                    write(connfd, s, strlen(s));
                } else if (n == 0) {
                    close(connfd);
                    client[i] = -1;
                    FD_CLR(connfd, &allset);
                }
                if (--nready <= 0) {
                    break;
                }
            }
        }
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
