/*Isaiah Scheel
384 - Networks
Dr. Hauser
12/1/2017
Client
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
#include<time.h>
#define SERVER_PORT 5409
#define MILLION 1000000
int main(int argc, char * argv[]){
  FILE *fp;
  double diff;
  struct hostent *hp;
  struct sockaddr_in sin;
  char *host;
  int s, new_s;
  int len;
  struct timespec start;
  struct timespec end;
  long seconds;
  long ns;
  char packets[2000000];
  double times[100001];
  double sum = 0;
  int size = 1;
  double time = 0;
  int first = 1;
  double tp;

    int clientSocket, portNum, nBytes;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr("152.117.180.159");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    addr_size = sizeof serverAddr;


////////////////////////////////////////1////////////////////////////////////

for(int m = 0; m < 11; m++){
  for(int i = 0; i < size; i++){
    packets[i] = 'x';
  }

for(int l = 0; l < 100000; l++){

  packets[2000000 - 1] = '\0';
  nBytes = strlen(packets) + 1;

  clock_gettime(CLOCK_MONOTONIC, &start);
  sendto(clientSocket,packets,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);
  recvfrom(clientSocket,packets,200000,0,NULL, NULL);
  clock_gettime(CLOCK_MONOTONIC, &end);

if ( (end.tv_nsec - start.tv_nsec) < 0 ) {
  seconds = end.tv_sec - start.tv_sec - 1;
  ns = 1000000000 + end.tv_sec - start.tv_nsec;
} else {
  seconds = end.tv_sec - start.tv_sec;
  ns = end.tv_nsec - start.tv_nsec;
}
diff = ns/MILLION + seconds*1000;
times[l] = diff;
}

for(int d = 0; d < 100000; d++){
  sum = sum + times[d];
}

time = sum/100000;
sum = 0;
printf("Size: %dB took %e ms \n",size , time );
if(first == 1){
  size = size + 99;
  first = 0;
}
else{
size = size + 100;
}
}

////////////////////////////////2////////////////////////////////////////////

for(int m = 0; m < 8; m++){
  if(m == 0){
    size = 1;
  }
  else if(m == 1){
    size = 2;
  }
  else if(m == 2){
    size = 4;
  }
  else if(m == 3){
    size = 8;
  }
  else if(m == 4){
    size = 16;
  }
  else if(m == 5){
    size = 32;
  }
  else if(m == 6){
    size = 64;
  }
  else if(m == 7){
    size = 128;
  }
  for(int i = 0; i < size * 1000; i++){
    packets[i] = 'x';
  }

for(int l = 0; l < 100; l++){

  nBytes = strlen(packets) + 1;
  int packetSize = size * 1000;
  int counter = 0;
  int flag = 1;
  char temp[4088];
  for(int k = 0; k < 4088; k++){
    temp[k] = 'x';
  }
  while(flag){
  if(packetSize > 4088){
      counter+=4088;
      if(packetSize <= counter){
        flag = 0;
      }

    clock_gettime(CLOCK_MONOTONIC, &start);
    sendto(clientSocket,temp,1024,0,(struct sockaddr *)&serverAddr,addr_size);
    recvfrom(clientSocket,temp,1024,0,NULL, NULL);
    clock_gettime(CLOCK_MONOTONIC, &end);
  }
  else{
    clock_gettime(CLOCK_MONOTONIC, &start);
    sendto(clientSocket,packets,size * 1000,0,(struct sockaddr *)&serverAddr,addr_size);
    recvfrom(clientSocket,packets,size * 1000,0,NULL, NULL);
    clock_gettime(CLOCK_MONOTONIC, &end);
    //printf("Flag 2\n" );
    flag = 0;
  }
}

if ( (end.tv_nsec - start.tv_nsec) < 0 ) {
  seconds = end.tv_sec - start.tv_sec - 1;
  ns = 1000000000 + end.tv_sec - start.tv_nsec;
} else {
  seconds = end.tv_sec - start.tv_sec;
  ns = end.tv_nsec - start.tv_nsec;
}
diff = ns/MILLION + seconds*1000;
times[l] = diff;
}

for(int d = 0; d < 100; d++){
  sum = sum + times[d];
}

time = sum/100;
sum = 0;
printf("Size: %dkb took %e ms \n",size , time );
time = time/1000;
tp = (size*1000*8)/time;
printf("Throughput: %e bits/second \n", tp);
}

/////////////////////////////////////////////3///////////////////////////////
int iterations;
for(int m = 0; m < 8; m++){
  if(m == 0){
    size = 1;
  }
  else if(m == 1){
    size = 2;
  }
  else if(m == 2){
    size = 5;
  }
  else if(m == 3){
    size = 10;
  }
  else if(m == 4){
    size = 15;
  }
  else if(m == 5){
    size = 20;
  }
  else if(m == 6){
    size = 25;
  }
  else if(m == 7){
    size = 30;
  }
  for(int i = 0; i < size * 1000; i++){
    packets[i] = 'x';
  }
iterations = 100000 / size;
for(int l = 0; l < iterations; l++){

  len = strlen(packets) + 1;
   packetSize = size * 1000;
   counter = 0;
   flag = 1;
  char temp[4088];
  for(int k = 0; k < 4088; k++){
    temp[k] = 'x';
  }
  while(flag){
  if(packetSize > 4088){
      counter+=4088;
      if(packetSize <= counter){
        flag = 0;
      }

    clock_gettime(CLOCK_MONOTONIC, &start);
    sendto(clientSocket,temp,4088,0,(struct sockaddr *)&serverAddr,addr_size);
    recvfrom(clientSocket,temp,4088,0,NULL, NULL);
    clock_gettime(CLOCK_MONOTONIC, &end);
  }
  else{
    clock_gettime(CLOCK_MONOTONIC, &start);
    sendto(clientSocket,packets,packetSize,0,(struct sockaddr *)&serverAddr,addr_size);
    recvfrom(clientSocket,packets,packetSize,0,NULL, NULL);
    clock_gettime(CLOCK_MONOTONIC, &end);
    flag = 0;
  }
}

if ( (end.tv_nsec - start.tv_nsec) < 0 ) {
  seconds = end.tv_sec - start.tv_sec - 1;
  ns = 1000000000 + end.tv_sec - start.tv_nsec;
} else {
  seconds = end.tv_sec - start.tv_sec;
  ns = end.tv_nsec - start.tv_nsec;
}
diff = ns/MILLION + seconds*1000;
times[l] = diff;
}

for(int d = 0; d < iterations; d++){
  sum = sum + times[d];
}

time = sum/iterations;
sum = 0;
printf("Size: %dkb need %d iterations and took %e ms\n",size , iterations , time);
time = time/1000;
tp = (size*1000*8)/time;
printf("Throughput: %e bits/second \n", tp);
}


}
