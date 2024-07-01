#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int land[101][101] = {0};
    land[1][1] = 1;
    
    for(int i = 0; i < puddles.size(); ++i){
        land[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    for(int i = 1; i < n + 1; ++i){
        for(int j = 1; j < m + 1; ++j){
            int x = 0;
            int y = 0;
            
            if(land[i][j] == -1){
                continue;
            }
            if(land[i - 1][j] != -1){
                x = land[i - 1][j];
            }
            if(land[i][j - 1] != -1){
                y = land[i][j - 1];
            }
            land[i][j] += (x + y) % 1000000007;
        }
    }
    
    return land[n][m];
}