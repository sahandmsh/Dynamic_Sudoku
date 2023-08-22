# Dynamic_Sudoku

This code includes a Sudoku solver, that provides all feasible solutions for a given board with initial values. The code is dynamic, meaning that it is
capable of solving Sudokus with any block size. The definition of block size is explained in the following example:

* Each block is (block size)\*(block size), e.g., in the following the block size is 3, and the size of the board is (3\*3) \* (3\*3). It is noted that,
each empty entry is shown with "0".

![Screenshot 2023-08-22 at 10 12 46 AM](https://github.com/sahandmsh/Dynamic_Sudoku/assets/82970651/6c070202-4275-4e8b-9262-e121f2a39cd2)


* The class Sudoku gets the block size, and a 2-d vector as inputs (2d- vector includes the initial values for the board):
![Screenshot 2023-08-22 at 10 20 30 AM](https://github.com/sahandmsh/Dynamic_Sudoku/assets/82970651/4a825e61-28c3-4fd7-8307-ec82675d8870)

* The result for the example given above is:

  ![Screenshot 2023-08-22 at 10 16 29 AM](https://github.com/sahandmsh/Dynamic_Sudoku/assets/82970651/2e7f8906-26ad-43dd-b443-9e300c31ab15)
