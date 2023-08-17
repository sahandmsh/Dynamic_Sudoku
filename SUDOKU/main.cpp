#include <iostream>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

class sudoku{
    vector <vector <int>> input_board;
    int block_s;
public:
    sudoku(int,vector <vector <int>>);
    void display(vector <vector <int>>);
    bool solve(vector <vector <int>>,int,int);
};

sudoku::sudoku(int block_s,vector <vector <int>> input_board):block_s(block_s), input_board(input_board){
    cout<<"INITIAL BOARD\n";
    display(input_board);
    solve(input_board,0,0);
}

void sudoku::display(vector <vector <int>> board){
    int counter1 = 0, counter2 = 0;
    cout<<"\n ";
    for (int j =65;j<block_s*block_s+65;++j){
        cout<<static_cast<char>(j)<<"   ";
    }
    for (int i=0;i<block_s*block_s;++i){
        cout<<"\n";
        if (counter2%block_s == 0){
            for (int k=0;k<block_s*block_s*4;++k){cout<<"-";}
            cout<<"\n";
        }
        cout<<"|";
        counter2++;
        for (int j=0;j<block_s*block_s;++j){
            counter1++;
            cout<<board[i][j];
            if (counter1%block_s==0){
                string o = (board[i][j]<10) ? " | ": "| ";
                cout<<o;
            }
            else {string o = (board[i][j]<10) ? "   ": "  ";
                cout<<o;
            }
        }
        cout<<static_cast<char>(counter2+96);
    }
    cout<<"\n";
    for (int k=0;k<block_s*block_s*4;++k){cout<<"-";}
    cout<<"\n";
}

bool sudoku:: solve(vector <vector <int>> board,int row,int column){
    if (row>= block_s*block_s){
        cout<<"SOLVED SUDOKU:\n";
        display(board);
        return true;
    }
    else if (board[row][column] != 0){
        solve(board, row+(column+1)/(block_s*block_s), (column+1)%(block_s*block_s));
    }
    else{
        bitset<9*9> row_bits,column_bits,block_bits,all_bits;
        for (int j=block_s*block_s;j<9*9;++j){
            row_bits.set(j);
            column_bits.set(j);
            block_bits.set(j);
            all_bits.set(j);
        }
        for (int i=0;i<block_s*block_s;++i){
            if (board[row][i]>0){row_bits.set(board[row][i]-1);}
            if (board[i][column]>0){column_bits.set(board[i][column]-1);}
        }
        for (int i=(row/block_s)*block_s;i<(row/block_s)*block_s+block_s;++i){
            for (int j=(column/block_s)*block_s;j<(column/block_s)*block_s+block_s;++j){
                if (board[i][j]>0){block_bits.set(board[i][j]-1);}
            }
        }
        all_bits = row_bits|column_bits|block_bits;
        if ( all_bits.all() ){
            return false;
        }
        else{
            for (int i=0;i<block_s*block_s;++i){
                if (!all_bits[i]){
                    board[row][column] = i+1;
//                    solve(board, row+(column+1)/(block_s*block_s), (column+1)%(block_s*block_s));  // generates all possible solutions
                    if (solve(board, row+(column+1)/(block_s*block_s), (column+1)%(block_s*block_s))==true){return true;}  // generates first solution found
                }
            }
        }
    }
    return false;
}

int main() {
    vector <vector <int>> input_board =
                  { {4,5,0,0,0,0,0,0,0},
                    {0,0,2,0,7,0,6,3,0},
                    {0,0,0,0,0,0,0,2,8},
                    {0,0,0,9,5,0,0,0,0},
                    {0,8,6,0,0,0,2,0,0},
                    {0,2,0,6,0,0,7,5,0},
                    {0,0,0,0,0,0,4,7,6},
                    {0,7,0,0,4,5,0,0,0},
                    {0,0,8,0,0,9,0,0,0},};
    sudoku s3(3,input_board); // a 9*9 Sudoku example (the size of each block is 3*3)
    
    
    input_board =
                  { {1,2,0,0},
                    {0,0,1,2},
                    {0,3,0,0},
                    {4,0,0,3},};
    sudoku s2(2,input_board); // a 4*4 Sudoku example (the size of each block is 2*2)
}
