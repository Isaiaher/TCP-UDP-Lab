# TCP-UDP-Lab
A lab assignment which I measured the different throughput and package style for UDP and TCP


# TCP 

#### Problem 1: 
First we started with a TCP echo program and measured the latency of 1 byte - 1,000 bytes and got the following by running each size 10,000 times and getting the average time it took:

Size: 1 took 1.480800e+00 ms

Size: 100 took 2.038600e+00 ms 

Size: 200 took 2.100000e+00 ms 

Size: 300 took 2.060800e+00 ms 

Size: 400 took 2.181300e+00 ms 

Size: 500 took 2.253700e+00 ms 

Size: 600 took 2.061700e+00 ms 

Size: 700 took 2.117400e+00 ms 

Size: 800 took 2.155900e+00 ms 

Size: 900 took 2.339300e+00 ms 

Size: 1000 took 2.160900e+00 ms 

We used clock monotonic due to the it being wall clock time and that is what we want due to the process being done on multiple processors and computers. The precision of clock monotonic is to nanoseconds, but we converted to milliseconds to have even units for everyone. This will apply to every other problem as well.

Also, the running it 10,000 and taking the average is the same for every problem as well.

#### Problem 2: 

We now can find the throughput by dividing the bits of the message, we got : 



Size: 1kb took 2.489000e+00 ms 
Throughput: 3.214142e+06 bits/second 
Size: 2kb took 4.135000e-01 ms 
Throughput: 3.869407e+07 bits/second 
Size: 4kb took 7.624000e-01 ms 
Throughput: 4.197272e+07 bits/second 
Size: 8kb took 1.490000e+00 ms 
Throughput: 4.295302e+07 bits/second 
Size: 16kb took 2.738500e+00 ms 
Throughput: 4.674092e+07 bits/second 
Size: 32kb took 6.451400e+00 ms 
Throughput: 3.968131e+07 bits/second 
Size: 64kb took 1.292540e+01 ms 
Throughput: 3.961193e+07 bits/second 
Size: 128kb took 2.528160e+01 ms 
Throughput: 4.050377e+07 bits/second 


We accomplished this by getting the average of 10,000 times in seconds and the message size in bits and dividing them.

#### Problem 3:
We sent 100MB in iterations for certain message sizes from 1KB - 30KB. We chose 1KB, 2KB, 5KB, 10KB, 15KB, 20KB, 25KB, and 30KB


Size: 1kb need 100000 iterations and took 1.587500e-01 ms

Throughput: 5.039370e+07 bits/second 

Size: 2kb need 50000 iterations and took 3.499200e-01 ms

Throughput: 4.572474e+07 bits/second 

Size: 5kb need 20000 iterations and took 8.537500e-01 ms

Throughput: 4.685212e+07 bits/second 

Size: 10kb need 10000 iterations and took 1.737600e+00 ms

Throughput: 4.604052e+07 bits/second 

Size: 15kb need 6666 iterations and took 2.531053e+00 ms

Throughput: 4.741110e+07 bits/second 

Size: 20kb need 5000 iterations and took 3.501600e+00 ms

Throughput: 4.569340e+07 bits/second 

Size: 25kb need 4000 iterations and took 4.303000e+00 ms

Throughput: 4.647920e+07 bits/second 

Size: 30kb need 3333 iterations and took 5.079208e+00 ms

Throughput: 4.725146e+07 bits/second 



So does this data make sense and correspond to my partner? Well I believe it makes sense because I used my own personal laptop which has a NIC speed of 1-Gbps and ran it to my server which was running on a computer in Morken 212 which also has a NIC speed of 1-Gbps. Compared to other people in the class, our times were very small, so very fast, so we aren’t sure if we messed up somewhere or if we just happened to have fast times.
All of Jacob’s times will be slightly faster because he used a computer in Morken and had the same server as me on the desktop so he was wired in while I was using the wi-fi in there. 

I have attached an excel file with graphs and charts and I will comment on them here:

#### Problem 1 table and graph : 

	The first table is what I expected. Sending 1 byte was the fastest, but it wasn’t linear with bigger messages taking longer because of TCP overhead and that sending more bytes wasn’t making it go slower. The graph showed this with its ups and downs and nonlinear curve.

#### Problem 2 table and graph:

	The second table was pretty interesting. Again the smallest size, this time 1 KB, took the shortest amount have time, but it jumped straight up and worked its way up to a max. After this max, it slowly went down and leveled out to about constant. I don’t have much reasoning to this, but it shows that small data sets will send fast like the 1 KB, and medium sized will have a max, but it will have a leveling out point eventually.

#### Problem 3 table and graph:

	The third table and graph is strange. The first size, 1 KB again, had the highest time and then each one after goes up and down with no real correlation. My best guess on this graph is that because I went every 5 values to save time, there could be more points in the middle that kind of level it out and make it more constant. Because the graph does make it look all over the place, but the numbers are actually quite similar, with the first being larger, but still comparable. So my conclusion is that they are supposed to be similar values, my first one might have just got messed up a tad.
