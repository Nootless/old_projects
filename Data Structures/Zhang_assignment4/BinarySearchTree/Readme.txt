Name: Justin Zhang (811-735-055) 
Email: jlz44196@uga.edu

To compile:
make
To run: 
./main <input file name>
To clean:
make clean

getNumSingleParent - T(n/2) = T(n/2) + T(n/2) + 1 = 2T(n/2) + 1
This function traverses through the entire tree and checks every single
node to see if it only has one child by recursively traversing through each node.
This causes at most 2 recursive calls through each function call. 
a = 2
b = 2
d = 0
2 > 2^0
T(n) is O(n^(log_2(2))) =
T(n) is O(n)

getNumLeafNodes - 
This function calls the recursive function leafNodes, which
traverses through every single node and checks if they are a leaf node.
Because of this, every single node, at most, can cause 2 recursive calls.
T(n/2) + T(n/2) + 1 = 2T(n/2) + 1
a = 2
b = 2
d = 0
2 > 2^0
T(n) is O(n^(log_2(2))) =
T(n) is O(n)

getSumofSubtrees - 
The first function subtreeNode is called in order to find where
the sub node is at. Since it only traverses half 
the branches, it has a recursion relationship of T(n) = T(n/2) + 1. 
The second function sumSubtree is called to add up all
the values in the subtree. It has to traverse half the
tree each time, making it T(n) = T(n/2) + T(n/2) + 1 = 2T(n/2) + 1.
Both of these happen sequentially, making their total recursive relationship
T(n) = (2T(n/2) + 1) + (T(n/2) + 1) 
T(n) = 3T(n/2) + 2
a = 3
b = 2
d =  0
f(n) = 2
3 >  2^0
T(n) is O(n^(log_2(3))) 
