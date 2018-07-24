/*Isaiah Scheel
384 - Networks
George Hauser
11/29/2017
Server Lab
gcc using ubuntu was used to compile this code.
Lab #3
All information regarding this lab can be found in the lab report.
Apologies for sloppy code and not using variables for the random
numbers in the lab.
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include<stdlib.h>
#include<time.h>
#define SERVER_PORT 5401
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

  if (argc==2) {
      host = argv[1];
    }
  else {
    fprintf(stderr, "usage: simplex-talk host\n");
    exit(1);
  }

  hp = gethostbyname(host);
  if (!hp) {
    fprintf(stderr, "simplex-talk: unknown host: %s\n", host);
    exit(1);
  }

  bzero((char *)&sin, sizeof(sin));
  sin.sin_family = AF_INET;
  bcopy(hp->h_addr, (char *)&sin.sin_addr, hp->h_length);
  sin.sin_port = htons(SERVER_PORT);

  if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
    perror("simplex-talk: socket");
    exit(1);
  }
  if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0){
    perror("simplex-talk: connect");
    close(s);
    exit(1);
  }
////////////////////////////////////////1////////////////////////////////////

for(int m = 0; m < 11; m++){
  for(int i = 0; i < size; i++){
    packets[i] = 'x';
  }

for(int l = 0; l < 10000; l++){

  packets[20000 - 1] = '\0';
  len = strlen(packets) + 1;

  clock_gettime(CLOCK_MONOTONIC, &start);
  send(s, packets, size, 0);
  recv(s, packets, size, 0);
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

for(int d = 0; d < 10000; d++){
  sum = sum + times[d];
}

time = sum/10000;
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

for(int l = 0; l < 10000; l++){

  packets[20000 - 1] = '\0';
  len = strlen(packets) + 1;

  clock_gettime(CLOCK_MONOTONIC, &start);
  send(s, packets, size * 1000, 0);
  recv(s, packets, size * 1000, 0);
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

for(int d = 0; d < 10000; d++){
  sum = sum + times[d];
}

time = sum/10000;
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

  packets[20000 - 1] = '\0';
  len = strlen(packets) + 1;

  clock_gettime(CLOCK_MONOTONIC, &start);
  send(s, packets, size * 1000, 0);
  recv(s, packets, size * 1000, 0);
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
