#include "ping.h"

int main(int argc, char *argv[])
{
    //printf("ip: %s\n", argv[1]);
    int sockfd;
    char send_buff[MAX_BUFF_SIZE];
    char recv_buff[MAX_BUFF_SIZE];
    struct sockaddr_in to_addr, from_addr;
    int from_addr_len = 0;
    struct icmp *icmp = malloc(sizeof(struct icmp *));

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    icmp->icmp_type     = ICMP_ECHOREPLY;
    icmp->icmp_code     = 0;
    icmp->icmp_cksum    = 0;
    icmp->icmp_id       = getpid();
    icmp->icmp_seq      = 0;

    printf("PING %s (%s) %d bytes of data.\n", argv[1], argv[1], 56);

    to_addr.sin_family  = AF_INET;
    inet_aton(argv[1], to_addr.sin_addr);

    sendto(sockfd, icmp, sizeof(icmp), 0, (struct sockaddr *)&to_addr, sizeof(to_addr));
    recvfrom(sockfd, recv_buff, sizeof(recv_buff), 0, (struct sockaddr *)&from_addr, &from_addr_len);

    struct ip *ip_ptr = (struct ip *) recv_buff;
    printf("recv_buff: %s\n", recv_buff);
    printf("ip_version: %d\tip_header_len: %d\n", ip_ptr->ip_v, ip_ptr->ip_hl<<2);
    char *ip_src = inet_ntoa(ip_ptr->ip_src);
    char *ip_dst = inet_ntoa(ip_ptr->ip_dst);
    printf("ip_src: %s\tip_dst: %s\n", ip_src, ip_dst);

    free(icmp);


    return 0;
}
