#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

void str_cli(int sockfd);

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in srvaddr;
    memset(&srvaddr, 0, sizeof(srvaddr));
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(59999);
    inet_pton(AF_INET, "127.0.0.1", &srvaddr.sin_addr);
    int rst;
    if ((rst = connect(sockfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr))) < 0) {
        perror("connect error");
        exit(1);
    }
    str_cli(sockfd);
    return 0;
}

void str_cli(int sockfd) {
    char sendb[100], recvb[100];
    int stdineof = 0;
    fd_set rset;
    FD_ZERO(&rset);
    while (1) {
        FD_SET(sockfd, &rset);
        if (stdineof == 0) {
            FD_SET(fileno(stdin), &rset);
        }
        int nfds = max(sockfd, fileno(stdin)) + 1;

        int rst = select(nfds, &rset, NULL, NULL, NULL);
        if (rst < 0) {
            perror("select error");
            exit(1);
        }

        if (FD_ISSET(sockfd, &rset)) {
            int n = read(sockfd, recvb, 100);
            if (n == 0) {
                if (stdineof == 1) {
                    printf("server terminated normally\n");
                    return;
                } else {
                    printf("server terminated prematurely\n");
                    return;
                }
            } else if (n < 0) {
                perror("read error");
                exit(1);
            }
            printf("n: %d, echo: %s", n, recvb);
        }

        if (FD_ISSET(fileno(stdin), &rset)) {
            int n = read(fileno(stdin), sendb, 100);
            if (n == 0) {
                stdineof = 1;
                shutdown(sockfd, SHUT_WR);
                FD_CLR(fileno(stdin), &rset);
                continue;
            }
            sendb[n] = '\0';
            printf("input: %s", sendb);
            write(sockfd, sendb, 100);
        }
    }
}