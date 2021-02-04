# I/O HW1

* Snapshot of Sequential Read  
![](https://i.imgur.com/tTmPM3f.png)

* Snapshot of Sequential Write  
![](https://i.imgur.com/nUIzPBg.png)

* Snapshot of Sequential Write (using O_DIRECT)  
![](https://i.imgur.com/XZ62nA4.png)

* Snapshot of Random Read  
![](https://i.imgur.com/5gXni0Q.png)

* Snapshot of Random Write  
![](https://i.imgur.com/mVSRoZM.png)

* Snapshot of Random Write (using O_DIRECT)  
![](https://i.imgur.com/Mdkbvqo.png)

---

#### 1. Compare and explain your results of Sequential Read, Sequential Write and (O_DIRECT) Sequential Write.  

* execution time: Sequential Read > (O_DIRECT) Sequential Write > Sequential Write  

It takes longer to do Sequential Read since we need to get the data from disk if it is not cache.  
Sequential Write do ***write back*** while (O_DIRECT)Sequential Write do ***write through***  

#### 2. Compare and explain your results of Random Read, Random Write and (O_DIRECT) Random Write.  

* execution time: (O_DIRECT) Random Write >Random Read > Random Write  

It takes longer to do Random Read than write since we need to get the data from disk if it is not cache.  
For (O_DIRECT) Random Write, it takes more seek time and rotational latency. So it takes longer than Random Write.  

#### 3.	Compare and explain your results of Sequential Read and Random Read.  

* execution time: Random Read>Sequential Read  

The seek time and ratational latency of Sequential Read much less than those of Random Read.  

#### 4.	Compare and explain your results of Sequential Write and Random Write.  

* execution time: Random Write> Sequential Write  

The seek time and ratational latency of Sequential Write much less than those of Random Write.  

#### 5.	Compare and explain your results of (O_DIRECT) Sequential Write and (O_DIRECT) Random Write.  

* execution time: (O_DIRECT) Random Write>(O_DIRECT) Sequential Write  

The seek time and ratational latency of (O_DIRECT)Sequential Write much less than those of (O_DIRECT)Random Write.







