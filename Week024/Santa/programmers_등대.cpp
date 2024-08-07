#include <string>
#include <vector>

using namespace std;

vector<bool> isOn;
vector<vector<int>> tree; 
int answer = 0;

void DFS(int currentNode, int parentNode)
{   
    for(int idx = 0; idx < tree[currentNode].size(); ++idx)
    {
        if(tree[currentNode][idx] != parentNode)
        {
            DFS(tree[currentNode][idx], currentNode);
            
            if(!isOn[currentNode] && !isOn[tree[currentNode][idx]])
            {
                isOn[currentNode] = true;
                answer++;
            }
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {

    
    isOn.resize(n + 1);
    tree.resize(n + 1, vector<int>(0));

    for(vector<int> lh : lighthouse)
    {
        tree[lh[0]].push_back(lh[1]);
        tree[lh[1]].push_back(lh[0]);
    }
    
    DFS(1,1);
    
    return answer;
}