#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int row = board[0].size();
    int col = board.size();
    
    vector<vector<int>> acc_sum(row + 1, vector<int>(col + 1));
    
    // [type, r1, c1, r2, c2, degree]
    for(int i = 0; i < skill.size(); ++i){
        int type = skill[i][0];
        int row1 = skill[i][1];
        int col1 = skill[i][2];
        int row2 = skill[i][3];
        int col2 = skill[i][4];
        int degree;
        
        if(type == 1){
            degree = skill[i][5] * (-1);
        }else{
            degree = skill[i][5];
        }
        
        acc_sum[row1][col1] += degree;
        acc_sum[row2 + 1][col2 + 1] += degree;
        acc_sum[row1][col2 + 1] -= degree;
        acc_sum[row2 + 1][col1] -= degree;
    }
    
    for(int i = 0; i < row; ++i){
        int temp_sum = 0;
        for(int j = 0; j < col; ++j){
            acc_sum[j][i] += temp_sum;
            temp_sum = acc_sum[j][i];
        }
    }
    
    for(int i = 0; i < col; ++i){
        int temp_sum = 0;
        for(int j = 0; j < row; ++j){
            acc_sum[i][j] += temp_sum;
            temp_sum = acc_sum[i][j];
        }
    }
    
    for(int i = 0; i < col; ++i){
        for(int j = 0; j < row; ++j){
            if(board[i][j] + acc_sum[i][j] > 0){
                answer++;
            }
        }
    }
    
    return answer;
}