#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n;
char board[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define fastcpp ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void clearVisited();
int BFS();

int main(){
    fastcpp;

    cin >> n;

    int abNormal = 0;
    int normal = 0;
    
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < n; j++){
            board[i][j] = temp[j];
        }
    }

    normal = BFS();

    clearVisited();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'G'){
                board[i][j] = 'R';
            }
        }
    }

    abNormal = BFS();

    cout << normal << " " << abNormal;

    return 0;
}

void clearVisited(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            vis[i][j] = false;
        }
    }
}

int BFS(){
    int cnt = 0;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(vis[x][y]){
                continue;
            }

            cnt++;
            // 탐색할 좌표 pair<X, Y>
            queue<pair<int, int> > q;
            vis[x][y] = 1;
            q.push(make_pair(x, y));

            while(!q.empty()){
                pair<int, int> cur = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    // n*n 밖일 경우 continue
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n){
                        continue;
                    }
                    // 이미 방문 또는 같은 색이 아닐 경우
                    if(vis[nx][ny] == 1 || board[nx][ny] != board[x][y]){
                        continue;
                    }
                    
                    vis[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return cnt;
}