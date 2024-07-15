#include <string>
#include <vector>

using namespace std;

int cnt = 0;

bool isValid(vector<int>& board, int row, int col){
    for(int i = 0; i < row; ++i){
        if(board[i] == col || board[i] - i == col - row || board[i] + i == col + row){
            return false;
        }
    }
    
    return true;
}

void dfs(int n, int row, vector<int>& board) {
    if(n == row){
        cnt++;
        return;
    }
    
    for(int col = 0; col < n; ++col){
        board[row] = col;
        if(isValid(board, row, col)){
            dfs(n, row + 1, board);
        }
    }
}

int solution(int n) {
    vector<int> board(n);
    
    dfs(n, 0, board);
    
    return cnt;
}