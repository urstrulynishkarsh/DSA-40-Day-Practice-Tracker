#include<iostream>
#include<vector>
using namespace std;

bool issafe(vector<vector<char>> &board, int row, int col,char digit)
{
    int n=board.size();
    // row check
    for(int k=0;k<n;k++)
    {
        if(board[row][k]==digit)
        {
            return false;
        }
    }
    // col check
    for(int k=0;k<n;k++)
    {
        if(board[k][col]==digit)
        {
            return false;
        }
    }

    // 3*3 check
    for(int k=0;k<n;k++)
    {
        if(board[3*(row/3)+k/3][3*(col/3)+k%3]==digit)
        {
            return false;
        }
    }

    return true;
}
bool solve(vector<vector<char>> board)
{
    int n=board.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]=='.')
            {
                for(char ch='1';ch<='9';ch++)
                {
                    if(issafe(board,i,j,ch))
                    {
                        board[i][j]=ch;
                        if(solve(board))
                        {
                            return true;
                        }
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;

}
int main()
{
    vector<vector<char>> board(9, vector<char>(9));
    cout << "Enter Sudoku:\n";
    for(int i=0;i<9;i++)
    {
        string s;
        cin >> s;
        for(int j=0;j<9;j++)
        {
            board[i][j] = s[j];
        }
    }
    
    solve(board);
    cout << "\nSudoku:\n";
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}