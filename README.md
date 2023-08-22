# Dynamic_Sudoku

This code includes a Sudoku solver, that provides all feasible solutions for a given board with initial values. The code is dynamic, meaning that it is
capable of solving Sudokus with any block size. The definition of block size is explained in the following example:

* Each block is (block size)\*(block size), e.g., in the following the block size is 3, and the size of the board is (3\*3) \* (3\*3). It is noted that,
each empty entry is shown with "0".

![Screenshot 2023-08-22 at 10 12 46 AM](https://github.com/sahandmsh/Dynamic_Sudoku/assets/82970651/cc238019-a4c8-42ba-be25-ca8849c9a57d)



* The class Sudoku gets the block size, and a 2-d vector as inputs (2d- vector includes the initial values for the board):
![Screenshot 2023-08-22 at 10 20 30 AM](https://github.com/sahandmsh/Dynamic_Sudoku/assets/82970651/aca990fc-b4bb-47f8-8cc1-cdfee6df64c8)


* The result for the example given above is:

![Screenshot 2023-08-22 at 10 16 29 AM](https://github.com/sahandmsh/Dynamic_Sudoku/assets/82970651/bb959c8a-4e52-4242-9cd0-82bdfcb99dfe)




It is worth noting that backtracking is used to solve the Sudoku.
