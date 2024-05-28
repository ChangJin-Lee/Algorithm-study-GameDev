#include <string>
#include <vector>

using namespace std; 

int answer = 0;
vector<bool> isChecked (8, false);

void DFS(int depth, int remain, vector<vector<int>>& dungeons)
{  
    answer = depth > answer ? depth : answer;
  
    for(int idx = 0; idx < dungeons.size(); ++idx)
    {
        if(isChecked[idx]) continue;
        if(remain < dungeons[idx][0]) continue;
        
        isChecked[idx] = true;
        
        DFS(depth + 1, remain - dungeons[idx][1], dungeons);
        
        isChecked[idx] = false;
    }
}


int solution(int k, vector<vector<int>> dungeons) {

    DFS(0, k, dungeons);
    
    return answer;
}