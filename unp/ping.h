#ifndef PING_H
#define PING_H 1

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>

#include "my_util.h"

#define MAX_REQUEST_COUNT 5
#define MAX_BUFF_SIZE 4096


void send_icmp(int sockfd, char *host_str);
void recv_icmp(int sockfd);
unsigned short checksum(unsigned short *buf,int nword);

#endif
