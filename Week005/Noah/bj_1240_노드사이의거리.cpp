#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

// pair<linked node, distance>
vector<pair<int, int> > v[1001];

int main(){
    fastcpp;

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n - 1; i++){
        int a, b, dist;
        cin >> a >> b >> dist;
        v[a].push_back(make_pair(b, dist));
        v[b].push_back(make_pair(a, dist));
    }

    while(m--){
        int a, b;
        cin >> a >> b;
        queue<pair<int, int> > q;
        vector<bool> vis(n + 1);

        // bfs 탐색 시작점 지정 및 방문 표시
        q.push(make_pair(a, 0));
        vis[a] = true;

        // 큐에 좌표가 있을 동안 탐색 -> 이웃한 노드가 있음
        while(!q.empty()){
            
            int curNode = q.front().first;
            int curDist = q.front().second;
            // 현재 조회하는 노드는 pop
            q.pop();

            // 현재 노드가 타겟 노드와 일치할때
            if(curNode == b){
                cout << curDist << '\n';
                break;
            }

            // 연결되어있는 노드 탐색
            for(int i = 0; i < v[curNode].size(); i++){
                int nextNode = v[curNode][i].first;
                int nextDist = v[curNode][i].second;
                if(vis[nextNode] == true) {
                    continue;
                }else{
                    vis[nextNode] = true;
                    q.push(make_pair(nextNode, curDist + nextDist));
                }
            }
        }
    }

    return 0;
}
