/*Isaiah Scheel
384 - Networks
Dr. Hauser
12/1/2017
Server
gcc using ubuntu was used to compile this code.
Lab #4
UDP Portion
All other information can be found in the lab report,
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include<stdlib.h>
#define SERVER_PORT 5409
#define MAX_PENDING 5
#define MAX_LINE 1024
int main(){

  int udpSocket;
  int nBytes;
  char buffer[MAX_LINE];
  struct sockaddr_in serverAddr, clientAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size, client_addr_size;

  udpSocket = socket(PF_INET, SOCK_DGRAM, 0);
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(SERVER_PORT);
  serverAddr.sin_addr.s_addr = inet_addr("152.117.180.159");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  addr_size = sizeof serverStorage;
int count = 0;
  while(1){
    nBytes = recvfrom(udpSocket,buffer,1024,0,(struct sockaddr *)&serverStorage, &addr_size);
    //Use if you want updates on server running
  //  if(count%1000 == 0)
    printf("%d\n",count );
    count++;
    sendto(udpSocket,buffer,nBytes,0,(struct sockaddr *)&serverStorage,addr_size);
  }

  return 0;
}
