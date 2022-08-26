#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

int gettime(char *t, int n);

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("socket rst: %d\n", sockfd);

    struct sockaddr_in srvaddr;
    memset(&srvaddr, 0, sizeof(srvaddr));
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(59999);
    srvaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int rst;
    rst = bind(sockfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr));
    printf("bind rst: %d\n", rst);
    listen(sockfd, 8);
    printf("listen rst: %d\n", rst);

    // struct sockaddr_in cliaddr;
    // socklen_t cliaddr_len;
    int connfd;
    while (1) {
        connfd = accept(sockfd, NULL, NULL);
        // connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
        // inet_ntop();
        printf("connfd: %d\n", connfd);
        char *s = malloc(sizeof(char) * 20);
        s[20] = '\0';
        gettime(s, 20);
        printf("time: %s\n", s);
        write(connfd, s, strlen(s));
        close(connfd);
    }
    return 0;
}

int gettime(char *t, int n) {
    time_t timer = time(NULL);
    struct tm *tm_info = localtime(&timer);
    strftime(t, n, "%Y-%m-%d %H:%M:%S", tm_info);
    return n;
}