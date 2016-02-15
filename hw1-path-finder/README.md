# PathFinder

# Example
Warning: the Field row and column number exactly match with the row and column number you provide.
Otherwise, the PathFinder app will not work.
Provide the exact row # and column # 
range (5 <= row and column <=100): 
Enter the # of row: 12
Enter the # of column: 12
Type in the name of the file containing the Field
Enter the Field name: m1.txt
 
1  1  1  1  1  1  1  1  1  1  1  1  
1  0  0  0  1  0  0  0  0  0  0  1  
0  0  1  0  1  1  1  1  1  1  0  1  
1  1  1  0  1  0  0  0  0  1  0  1  
1  0  0  0  0  1  1  1  0  1  0  0  
1  1  1  1  0  1  0  1  0  1  0  1  
1  0  0  1  0  1  0  1  0  1  0  1  
1  1  0  1  0  1  0  1  0  1  0  1  
1  0  0  0  0  0  0  0  0  1  0  1  
1  1  1  1  1  1  0  1  1  1  0  1  
1  0  0  0  0  0  0  1  0  0  0  1  
1  1  1  1  1  1  1  1  1  1  1  1  
Before Traverse:
Traversing ...
* Entrance @ row: 4 column: 11 
* Exit @ row: 2 column: 0 
 
1  1  1  1  1  1  1  1  1  1  1  1  
1  0  0  0  1  X  X  X  X  X  X  1  
0  0  1  0  1  1  1  1  1  1  X  1  
1  1  1  0  1  0  0  0  0  1  X  1  
1  0  0  0  0  1  1  1  0  1  X  X  
1  1  1  1  0  1  0  1  0  1  X  1  
1  0  0  1  0  1  0  1  0  1  X  1  
1  1  0  1  0  1  0  1  0  1  X  1  
1  0  0  0  0  0  0  0  0  1  X  1  
1  1  1  1  1  1  0  1  1  1  X  1  
1  0  0  0  0  0  0  1  X  X  X  1  
1  1  1  1  1  1  1  1  1  1  1  1  
After Traverse: :( No path found