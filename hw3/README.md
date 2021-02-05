# I/O HW3

* Snapshot of C library’s execution time in 4B-sized and  4KB-sized.  
4B:  
![](https://i.imgur.com/Jp4U01o.png)  
4KB:  
![](https://i.imgur.com/x8JSH7V.png)  

* Snapshot of System Call’s execution time in 4B-sized and 4KB-sized.  
4B:  
![](https://i.imgur.com/hElTUjt.png)  
4KB:  
![](https://i.imgur.com/B8JJOGw.png)  

* Snapshot of Memory-mapped file’s execution time in 4B-sized and 4KB-sized.  
4B:  
![](https://i.imgur.com/TxBesUG.png)  
4KB:  
![](https://i.imgur.com/K17jnkM.png)  

* Compare the execution time under the different methods, C library, System Call and Memory-mapped file, in the  4B-sized and explain the results.  
    * Execute time: System Call >> C library / Memory-mapped file  
    * Both library call and memory-mapped file only makes system call to write disk when user buffer is full. And every system call takes up mcuh resource.  


* Compare the execution time under the different methods, C library, System Call and Memory-mapped file, in the 4KB-sized and explain the results.  
    * The time consumed does not differ from one another since the frequencie of system calls are similar.  

* Compare the execution time between 4B-sized and   4KB-sized in the C library and explain the results.  
    * The time consumed for 4B is slightly longer than that of 4KB since the frequency of replication is more.  


* Compare the execution time between 4B-sized and   4KB-sized in the System Call and explain the results.  
    * The time consumed for 4B is ***much*** longer than that of 4KB due to the difference of the frequency of system calls.  


* Compare the execution time between 4B-sized and   4KB-sized in the Memory-mapped file and explain the results.  
    * The time consumed for 4B is slightly longer than that of 4KB since the frequency of replication is more.  




