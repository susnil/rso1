/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 202304
 *
 * Created on March 7, 2018, 3:02 PM
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
int
main2()
{
    time_t czas;
    time( & czas );
    char * data = ctime( & czas );
    std::cout << "Data: " << "size:"<<sizeof(data) << data;
int server_sockfd, client_sockfd;
socklen_t server_len, client_len;
struct sockaddr_in server_address;
struct sockaddr_in client_address;
server_sockfd = socket (AF_INET, SOCK_STREAM, 0);
server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = htonl (INADDR_ANY);
server_address.sin_port = htons (9734);
server_len = sizeof (server_address);
bind (server_sockfd, (struct sockaddr *)
&server_address, server_len);
/*  Create a connection queue, ignore child exit
details and wait for clients.  */
listen (server_sockfd, 5);
signal (SIGCHLD, SIG_IGN);
while (1)
{
char ch;
printf ("server waiting\n");
/*  Accept connection.  */
client_len = sizeof (client_address);
client_sockfd = accept (server_sockfd,
(struct sockaddr *)
&client_address,
&client_len);
/*  Fork to create a process for this client
and perform a test to see
whether we're the parent or the child.
*/
if (fork () == 0)
{
/*  If we're the child, we can now
read/write to the client on client_sockfd.
The five second delay is just
for this demonstration.  */
read (client_sockfd, &ch, 1);
sleep (5);
    time_t czas;
    time( & czas );
    char * data = ctime( & czas );
write (client_sockfd, &data, sizeof(data));
close (client_sockfd);
exit (0);
}
/*  Otherwise, we must be the parent and our
work for this client is finished.  */
else
{
close (client_sockfd);
}
}
}


