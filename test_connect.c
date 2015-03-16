#include "my_sock.h"

int main(int argc, char *argv[])
{
    int sockfd, conn_rtn;
    int write_rtn, read_rtn;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 

    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(23456);
    inet_aton(argv[1], servaddr.sin_addr);
    conn_rtn = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    
    if ( conn_rtn < 0 ) {
        if ( errno == ETIMEDOUT ) {
            perror("connect timeout");
        } else if ( errno == ECONNREFUSED ) {
            perror("connect refused");
        } else if ( errno == EHOSTUNREACH ) {
            perror("connect unreach");
        }
    } 

    char input_str[20];
    char echo_str[20];
    while ( fgets(input_str, sizeof(input_str), stdin) != NULL ) {
        write(sockfd, input_str, sizeof(input_str));
        
        read_rtn = read(sockfd, echo_str, sizeof(echo_str));
        printf("echo: %s", echo_str);
        if ( read_rtn < 0 ) perror("read fail");
    }

    printf("close..%d\n", sockfd);
    close(sockfd);


    return;
}
