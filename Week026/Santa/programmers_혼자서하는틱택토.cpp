#include <string>
#include <vector>

using namespace std;


bool whoWin(vector<string>& board, char player)
{
    // 가로 새로 
    for(int i = 0; i < 3; ++i)
    {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true; 
        }
        
        else if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true; 
        }
    }
    
    // 대각선
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true; 
    }
    
    else if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }
    
    return false;
}

int solution(vector<string> board) {
    
    int xCount = 0; 
    int oCount = 0;
    
    for(string& row : board)
    {
        for(char c : row)
        {
            if(c == 'O')
            {
                oCount++;
            }
            else if(c == 'X')
            {
                xCount++;
            }
        }
    }
    
    // o, x의 개수가 맞지 않을 경우 무효
    if(xCount > oCount || oCount > xCount + 1)
    {
        return 0;
    }
    
    bool oWin = whoWin(board, 'O');
    bool xWin = whoWin(board, 'X');
    
    // 둘다 이김
    if(oWin && xWin)
    {
        return 0;
    }
    
    // O가 이겼을 경우 O가 X보다 하나 많음
    else if(oWin && oCount != xCount + 1)
    {
        return 0;
    }
    
    // x가 이겼을 경우 O와 X의 개수가 같음
    else if(xWin && oCount != xCount)
    {
        return 0;
    }
    
    return 1;
}