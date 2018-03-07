/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   client.cpp
 * Author: 202304
 *
 * Created on March 7, 2018, 3:09 PM
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <time.h>
int
main ()
{
int sockfd;
socklen_t len;
struct sockaddr_in address;
int result;
char ch = 'A';
sockfd = socket (AF_INET, SOCK_STREAM, 0);
address.sin_family = AF_INET;
address.sin_addr.s_addr = inet_addr ("127.0.0.1");
address.sin_port = htons (9734);
len = sizeof (address);
result = connect (sockfd, (struct sockaddr *) &address,
len);
if (result == -1)
{
perror ("oops: netclient");
exit (1);
}
char * data;
write (sockfd, &ch, 1);
read (sockfd, &data, 8);

int i=0;
printf ("serv%d\n.", sizeof(data));
for(i=0; i<sizeof(data);i++){
    printf("o %c",*(data+i));
}
printf ("servek connect%d, data: %c\n", sizeof(data), data);



close (sockfd);
exit (0);
}
