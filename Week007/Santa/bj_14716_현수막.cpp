#include <iostream> 
#include <queue>

using namespace std; 


bool map [251][251] = {false};
bool visited [251][251] = {false};

int directionY [8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int directionX [8] = {0, 1, 1, 1, 0, -1, -1, -1};

int n , m, value = 0; 

void BFS(int yp, int xp)
{
    // first == Y pos / second == X pos
    queue <pair<int, int> > myQ;
    
    myQ.push(make_pair(yp,xp));

    while(!myQ.empty())
    {
        pair<int, int> pos = myQ.front(); 
        myQ.pop();

        // q에서 뽑아낸 위치를 기준으로 8방향을 확인함 
        for(int idx = 0; idx < 8; idx++)
        {
            int yPos = pos.first + directionY[idx];
            int xPos = pos.second +directionX[idx];

            // map을 벗어나는지 확인
            if(yPos < 0 || yPos > m || xPos < 0 || xPos > n) 
            {
                // 벗어난다면 다음으로 
                continue;
            }

            // true == 글자, false == 빈칸
            if(map[yPos][xPos] == true)
            {
                // 이미 지난 노드로 체크
                map[yPos][xPos] = 0;
                // 큐에 넣기
                myQ.push(make_pair(yPos, xPos));
            }
        }
    }
}


int main ()
{
    // m == y, n == x
    cin >> m >> n;

    for(int y = 1; y <= m; y++)
    {
        for(int x = 1; x <= n; x++)
        {
            cin >> map[y][x];
        }
    }


    for(int y = 1; y <= m; y++)
    {
        for(int x = 1; x <= n; x++)
        {
            if(map[y][x] == true)
            {
                value++;
                BFS(y,x);
            }
        }
    }

    cout << value;

    return 0;
}