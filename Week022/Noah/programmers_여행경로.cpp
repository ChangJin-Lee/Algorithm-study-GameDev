#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited(10000);
vector<vector<string>> paths;

void dfs(int idx, vector<vector<string>>& tickets, vector<string> path){
    visited[idx] = true;
    
    path.push_back(tickets[idx][1]);
    
    if(path.size() == tickets.size() + 1){
        paths.push_back(path);
        return;
    }
    
    for(int i = 0; i < tickets.size(); ++i){
        if(!visited[i] && tickets[idx][1] == tickets[i][0]){
            dfs(i, tickets, path);
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    for(int i = 0; i < tickets.size(); ++i){
        vector<string> path;
        visited = {0, };
        
        if(tickets[i][0] == "ICN"){
            path.push_back("ICN");
            dfs(i, tickets, path);
        }
    }
    
    sort(paths.begin(), paths.end());
    
    return paths[0];
}