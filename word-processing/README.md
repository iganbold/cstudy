### Type justification APP
* Main Data Structure and Algorithm Description
* How to Run


-----------------------------------------
####* Main Data Structure and Algorithm Description

    Main Data Structure: 
        Single Linked List (char data[50], *nextPtr)
        Queue from Single Linked List for buffering
                         

    Algorithm (Read from a file and save to Linked list):
        1. read data from a file line by line
        2. find empty line (emptly line has the new line character and end of the line character) 
           then add "\n" to linked list to determine pragraph splitter while reading line by line.
        3. loop through each line find words and white space characters (used isspace() or ispunct()) 
           then add it to linked list while reading line by line.
    
    Algorithm (Type justification):
        1. loop through the list token by token
            1.1 keep track of number characsters for per line
            1.2 if track does reach the limit, then buffer (queueBufferPtr) the data from the list (startPtr) then delete the data from the list 
            1.3 check the data is "\n" if it is then split the prograph
            1.4 otherwise print the data from the buffer (1. data  2. spaces)
            1.5 if data is the last word of the line then print it ( 1. spaces 2. data)
        
    
--------------------------------------------
###*How to Run

    On the terminal:
        1. gcc app.c -o app (optional)
        2. ./app
        3. File name and location : file4-1.txt (example)
        4. Number of Characters between 40 and 100 for per line : 65 (example)