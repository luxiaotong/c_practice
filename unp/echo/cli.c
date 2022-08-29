#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

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
    char *s = malloc(100 * sizeof(char));
    while ((s = fgets(s, 100, stdin)) != NULL) {
        printf("gets: %s", s);
        write(sockfd, s, 100);
        int n = read(sockfd, s, 100);
        printf("n: %d, echo: %s", n, s);
    }
}