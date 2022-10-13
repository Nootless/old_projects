Name: Justin Zhang 
Email: jlz44196@uga.edu

Inside DoublyLinkedList folder:
    To compile:
        ./make
    To run:
        ./main <input file name>
    To clean:
        ./make clean
    

deleteSubsection:
To delete the subsections, loops through the entire list, which is O(n).
Then, when it finds the item it wants to delete, it calls the delete function.
The delete function also loops through the entire list to delete, which is O(n).
This causes the function to be O(n*n) or O(n^2) overall.

Time Complexity - O(n^2)

mode:
To get the mode, a loop first runs to iterate over every single list item, which
is O(n). Then, the amount of times a specific value occurs is found using the numOccurences
function. This runs through the entire list and finds how many times the same value occurs.
Since numOccurences is run O(n) times and has a complexity of O(n), the overall time
complexity is O(n*n) or O(n^2).

Time Complexity - O(n^2)

swapAlt:

To swap the values, a loop runs through the entire list, being O(n). Then, each
of the pointers for the back and front node are flipped so they are where the other 
used to be. Since the list is only iterated over once and the only statements are conditionals,
the complexity is O(n).

Time Complexity - O(n)