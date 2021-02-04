# I/O HW2

### ex_a.c uses write() and ex_b.c uses fwrite()

* Snapshot of Exercise 1 and Explain your results.  
![](https://i.imgur.com/LfuPu7M.png)  

**write()** makes 4096000 system calls whlie **fwrite()** writes all 'one byte's to buffer and makes system call when buffer is full.  

* Snapshot of Exercise 2 and Explain your results.  
![](https://i.imgur.com/ABi60FV.png)  

**write()** is faster in this case since it doesn't have to write buffer.

* Snapshot of Exercise 3 and Explain your results.  
![](https://i.imgur.com/643UhzI.png)  

**write()** is faster in this case since it doesn't have to write buffer.  

* Compare and explain the results from Exercise 1, Exercise 2, and Exercise 3.  
    * **execute time: ex1 > ex2 >ex3**  

The difference between the time consumed is based on the frequency of system calls since each I/O takes up more resource.  





