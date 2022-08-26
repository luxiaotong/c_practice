#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in srvaddr;
    memset(&srvaddr, 0, sizeof(srvaddr));
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(59999);
    inet_pton(AF_INET, "127.0.0.1", &srvaddr.sin_addr);
    int rst = connect(sockfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr));
    printf("connect rst: %d\n", rst);
    char s[100] = "";
    int n = read(sockfd, s, 100);
    printf("s: %s, n: %d\n", s, n);
    return 0;
}