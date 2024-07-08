#include<iostream> 
#include<vector>
#include<queue>

using namespace std; 

struct node
{
    int x;
    int y; 
    int depth;
};


int BFS(int n, int curX, int curY, int targetX, int targetY)
{
    vector<int> xPos = {-2, -2, 0, 0, 2, 2};
    vector<int> yPos = {-1, 1, -2, 2, -1, 1};

    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<node> myQ; 

    myQ.push({curX, curY, 0});


    while(!myQ.empty())
    {
        node temp = myQ.front();
        myQ.pop();

        if(temp.x == targetX && temp.y == targetY)
        {
            return temp.depth;
        }

        for(int idx = 0; idx < 6; ++idx)
        {
            int tempX = temp.x + xPos[idx];
            int tempY = temp.y + yPos[idx];
            int tempDepth = temp.depth;

            if(tempX < 0 || tempX >= n || tempY < 0 || tempY >= n) continue;
        
            if(visited[tempX][tempY]) continue;

            visited[tempX][tempY] = true;
            myQ.push({tempX, tempY, tempDepth + 1});
        }
    }

    return -1;
}


int main()
{
    int n, r1, c1, r2, c2;
    
    cin >> n >> r1 >> c1 >> r2 >> c2; 

    cout << BFS(n, r1, c1, r2, c2); 
    
    return 0;
}