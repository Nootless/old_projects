Justin Zhang (811-735-055)

To compile the program:
    make compile

To run the program:
    make run

To clean up the program:
    make clean

Pointer Practice

1.
a) char - size of 1 bytes
b) char * - size of 8 bytes
c) short - size of 2 bytes
d) short * - size of 8 bytes
e) int - size of 4 bytes
f) int *- size of 8 bytes
g) long - size of 8 bytes
h) long *- size of 8 bytes
i) int ** - size of 8 bytes
j) int *** - size of 8 bytes

2.

Run 1
a) 0x7ffe2c4fcb4c
b) 0x7ffe2c4fcb50
c) 0x7ffe2c4fcb54
d) 0x7ffe2c4fcb58
e) 0x7ffe2c4fcb5c

Run 2
a) 0x7ffe6d876a3c
b) 0x7ffe6d876a40
c) 0x7ffe6d876a44
d) 0x7ffe6d876a48
e) 0x7ffe6d876a4c

Run 3
a) 0x7ffdf4d89e1c
b) 0x7ffdf4d89e20
c) 0x7ffdf4d89e24
d) 0x7ffdf4d89e28
e) 0x7ffdf4d89e2c


f) The output is different for each run. This is because
   the pointer being printed is the memory address of the integer,
   the OS is choosing what memory location the value is stored at each time
   the program runs.
