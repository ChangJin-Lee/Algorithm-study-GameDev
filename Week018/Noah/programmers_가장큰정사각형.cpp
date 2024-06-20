#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];

    int row = board[0].size();
    int col = board.size();
    
    for(int i = 0; i < col - 1; ++i){
        for(int j = 0; j < row - 1; ++j){
            if(board[i + 1][j + 1] == 1){
                board[i + 1][j + 1] = min(board[i][j], min(board[i + 1][j], board[i][j + 1])) + 1;
                answer = max(answer, board[i + 1][j + 1]);
            }
        }
    }

    return answer * answer;
}