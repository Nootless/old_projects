Justin Zhang (jlz44196@uga.edu)
To compile:
    make
To run: 
    ./main <input file name>
To clean:
    make clean

Complexity of Merge:
    The merge function itself iterates through all the values given
    by the user twice: once to check for overlap, once to insert them 
    into the original list if there is no overlap. 
    Inside the first loop the search function is called, 
    which loops over every single value in the linked list, O(n). 
    This causes the first loop to have a complexity of O(n^2), as it's O(n*n). 
    Inside the second loop the insertItem function is called, it also calls the
    search function and then loops through the linked list to insert values.
    This causes the insertItem function to have a complexity of O(n + n), making
    the second loop O(n * 2n).  
    For the complexity of the merge function, it is O(2n^2 + n^2) = O(n^2).
Complexity of Find Common Elements:
    The find common elements function loops through the nodes in the linked list, O(n),
    then the list of values input by the user, O(n). It then deletes the values that 
    are not shared by the two lists from the original list. The delete function
    calls the search function, which loops through all the linked list value and
    then has a separate loop to go through the list to get to the desired value to 
    delete. This causes the delete function to have a complexity of O(n + n) = O(2n).
    As the delete is inside two nested loops, the complexity of the Find Common
    Elements function is O(2n * n * n) = O(n^3).