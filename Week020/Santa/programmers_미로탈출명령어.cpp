#include <string>
#include <vector>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
 
    string move = "dlru";
    
    vector<pair<int,int>> direction = { {1, 0}, {0, -1}, {0, 1}, {-1, 0} };
        
    int distance = abs(x - r) + abs(y - c);
    
    // 현재위치에서 도착지까지의 거리가 k 보다 크거나 홀수이면 안됨
    if(distance > k || (k - distance) % 2 == 1)
    {
        return answer = "impossible";
    }
    
    int curx = x; 
    int cury = y;
        
    // k횟수만큼 이동할 때까지 d l r u 순으로 움직인다.   
    while(k--)
    {
        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = curx + direction[dir].first;
            int ny = cury + direction[dir].second;

            // 맵을 벗어나면 안됨
            if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            
            distance = abs(nx - r) + abs(ny - c); 

            // dlru순서로 움직이면서 다음위치와 도착지까지의 거리가 k 보다 크면 다른 방향으로 움직인다. 
            if(distance > k) continue; 

            // 움직인 경로 저장
            answer += move[dir];

            // 현재 위치 업데이트
            curx = nx; 
            cury = ny;
            
            break;
        }
    }
    
    return answer;
}