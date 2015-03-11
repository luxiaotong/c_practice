#include "ping.h"

void send_icmp(int sockfd, char *host_str)
{
    char send_buff[MAX_BUFF_SIZE];
    //struct icmp *icmp_ptr = malloc(sizeof(struct icmp));
    struct icmp *icmp_ptr = (struct icmp *)send_buff;
    struct timeval *time_ptr = (struct timeval *)icmp_ptr->icmp_data;
    struct sockaddr_in to_addr;

    memset(&to_addr, 0, sizeof(to_addr));
    to_addr.sin_family  = AF_INET;
    inet_aton(host_str, &to_addr.sin_addr);


    int i = 0;
    for ( i = 0; i < MAX_REQUEST_COUNT; i ++ ) {
        memset(send_buff, 0, sizeof(send_buff));
        icmp_ptr->icmp_type     = ICMP_ECHOREPLY;
        icmp_ptr->icmp_code     = 0;
        icmp_ptr->icmp_id       = getpid();
        icmp_ptr->icmp_cksum    = 0;
        icmp_ptr->icmp_seq      = i;

        gettimeofday(time_ptr, NULL);
        printf("id: %d\tseq: %d\n", icmp_ptr->icmp_id, icmp_ptr->icmp_seq);
        //Todo: we should assign 64 to a parameter.
        icmp_ptr->icmp_cksum= checksum((unsigned short *)icmp_ptr, 64);
        //printf("cksum: %x\n", icmp_ptr->icmp_cksum);
        if ( sendto(sockfd, send_buff, 64, 0, 
                (struct sockaddr *)&to_addr, sizeof(to_addr)) < 0 ) {
            perror("sendto error");
            continue;
        }
        //sleep(1);
    }

    //free(icmp_ptr);
    return;
}

void recv_icmp(int sockfd)
{
    char recv_buff[MAX_BUFF_SIZE];
    struct sockaddr_in from_addr;
    int from_addr_len   = 0;
    int receive_count   = 0;
    int ip_header_len   = 0;
    int recv_len        = 0;
    int rtt             = 0;
    int pid             = getpid();

    while ( receive_count < MAX_REQUEST_COUNT ) {
        printf("Wait...\n");
        memset(recv_buff, 0, sizeof(recv_buff));
        memset(&from_addr, 0, sizeof(from_addr));

        if ( recvfrom(sockfd, recv_buff, sizeof(recv_buff), 0, 
                (struct sockaddr *)&from_addr, &from_addr_len) < 0 ) {
            perror("recvfrom error");
            continue;
        }

        recv_len = sizeof(recv_buff);
        struct ip *ip_ptr = (struct ip *) recv_buff;
        ip_header_len = ip_ptr->ip_hl<<2;
        
        struct icmp *icmp_ptr = (struct icmp *) (recv_buff + ip_header_len);
        
        if ( icmp_ptr->icmp_type == ICMP_ECHOREPLY && icmp_ptr->icmp_id == pid ) {
            struct timeval *time_start_ptr = (struct timeval *)icmp_ptr->icmp_data;
            struct timeval *time_end_ptr   = malloc(sizeof(struct timeval));
            gettimeofday(time_end_ptr, NULL);
            timeval_sub(time_end_ptr, time_start_ptr);
            rtt = time_end_ptr->tv_sec * 1000 + time_end_ptr->tv_usec / 1000;
            
            printf("%d byte from %s: icmp_seq=%u ttl=%d rtt=%.3f ms\n",
                    recv_len,
                    inet_ntoa(from_addr.sin_addr),
                    icmp_ptr->icmp_seq,
                    ip_ptr->ip_ttl,
                    rtt);

            receive_count ++;
        }
    }
    return;
}

unsigned short checksum(unsigned short *buf, int nword)
{
    unsigned long sum;
    
    for ( sum=0; nword>0; nword-- )
        sum += *buf++;
    sum = (sum>>16) + (sum&0xffff);
    sum += (sum>>16);
    
    return ~sum;
}


int main(int argc, char *argv[])
{
    //printf("ip: %s\n", argv[1]);
    int sockfd;
    int size=50*1024;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &size, sizeof(size));

    printf("PING %s (%s) %d bytes of data.%d\n", argv[1], argv[1], 56, getpid());

    send_icmp(sockfd, argv[1]);
    recv_icmp(sockfd);

    return 0;
}
