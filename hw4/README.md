# I/O HW4

* Snapshot of searching ‘passwd’ at root directory  
    Your program  
    ![](https://i.imgur.com/AMtzLC8.png)  

    By *find*  
    ![](https://i.imgur.com/wrw6m02.png)  
  
  
* Snapshot of searching ‘passwd’ at default directory (current directory)
    Your program  
    ![](https://i.imgur.com/C7HQV49.png)
  

    By *find*  
    ![](https://i.imgur.com/e44w0tl.png)  
    
* Briefly describe your design.  
    * Declare *search* function to get the directory and filename we searching for. And use *opendir()* to open the directory, return if *opendir()* fails.  
    * Declare a flag to identify whether the filename is found, and use an array to record the path.  
    * Use *entry* to record the pointer of *readdir*, record the path if the pointer !=NULL.  
    * If *entry* points to a directory(except for current dir or parent dir), trace down the directory. If *entry* points to the requested file, print out the path.  
    * Main function gets argument of directory name. Search current direcory if no argument passed  
    * If the searching is done and the flag==0, print out "cannot find the corresponding file."  
  
  