#include <iostream>
#include <queue>

using namespace std;

int grid[501][501];
bool vis[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;
int mx = 0;

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void BFS(int n, int m){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            if(vis[x][y] || grid[x][y] == 0){
                continue;
            }
            
            cnt++;

            queue<pair<int, int> > q;
            vis[x][y] = 1;
            q.push(make_pair(x, y));

            // 그림의 넓이
            int temp = 0;

            while(!q.empty()){
                temp++;
                pair<int, int> cur = q.front(); q.pop();

                for(int i = 0; i < 4; i++){
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    // n * m 밖의 범위일 경우 continue
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                        continue;
                    }
                    // 이미 방문 또는 색칠이 안되어있으면 continue
                    if(vis[nx][ny] || grid[nx][ny] != 1){
                        continue;
                    }
                    vis[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
            mx = max(mx, temp);
        }
    }
}

int main(){
    fastcpp;

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    BFS(n, m);

    cout << cnt << "\n" << mx;

    return 0;
}