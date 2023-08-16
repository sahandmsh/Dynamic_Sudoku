#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class sudoku{
    vector <vector <int>> input_board;
    int block_s;
public:
    sudoku(int);
    void display();
    bool solve(vector <vector <int>>,int,int);
};
sudoku::sudoku(int block_s):block_s(block_s){
//    input_board = vector <vector <int>> (block_s*block_s , vector<int> (block_s*block_s,0));
    input_board = { {4,5,0,0,0,0,0,0,0},
                    {0,0,2,0,7,0,6,3,0},
                    {0,0,0,0,0,0,0,2,8},
                    {0,0,0,9,5,0,0,0,0},
                    {0,8,6,0,0,0,2,0,0},
                    {0,2,0,6,0,0,7,5,0},
                    {0,0,0,0,0,0,4,7,6},
                    {0,7,0,0,4,5,0,0,0},
                    {0,0,8,0,0,9,0,0,0},
    };
    cout<<"INITIAL BOARD\n";
    display();
    solve(input_board,0,0);
}
void sudoku::display(){
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
            cout<<input_board[i][j];
            if (counter1%block_s==0){cout<<" | ";}
            else {cout<<"   ";}
        }
        cout<<static_cast<char>(counter2+96);
    }
    cout<<"\n";
    for (int k=0;k<block_s*block_s*4;++k){cout<<"-";}
    cout<<"\n";
}

bool sudoku:: solve(vector <vector <int>> board,int row,int column){
    if (row>= block_s*block_s){
        input_board = board;
        cout<<"SOLVED SUDOKU:\n";
        display();
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
                    solve(board, row+(column+1)/(block_s*block_s), (column+1)%(block_s*block_s));
//                    if (solve(board, row+(column+1)/(block_s*block_s), (column+1)%(block_s*block_s))==true){return true;}
                }
            }
        }
    }
    return false;
}






int main() {
    sudoku s(3);
}
