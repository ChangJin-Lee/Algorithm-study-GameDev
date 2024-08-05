#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'knightlOnAChessboard' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */
 
 int bfs(int i, int j, int n)
 {
     queue<tuple<int,int,int>> q;
     vector<vector<bool>> visited(n, vector<bool>(n,false));
     vector<pair<int,int>> Movable = {{i,j}, {-i,j}, {-i,-j}, {i,-j}, {j,i}, {-j,i}, {j,-i}, {-j,-i}};
     int Count = 10000000;
     
     q.push({0,0,0});
     visited[0][0] = true;
     
     while(!q.empty())
     {
         int cx = get<0>(q.front());
         int cy = get<1>(q.front());
         int cl = get<2>(q.front());
         q.pop();
         
         for(pair<int,int> NextMove : Movable)
         {
             int nx = cx + NextMove.first;
             int ny = cy + NextMove.second;
             int nl = cl + 1;
             
             if(0 <= nx && nx < n && 0 <= ny && ny < n)
             {
                 if(!visited[nx][ny])
                 {
                     q.push({nx,ny,nl});
                     visited[nx][ny] = true;
                     if(nx == n-1 && ny == n-1)
                     {
                         Count = min(Count, nl);
                     }
                 }
             }
         }
     }
     
     if(Count == 10000000)
     {
         return -1;
     }
     else
     {
         return Count;
     }
     
 }

vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int>> answer;
    for(int i = 1; i < n; ++i)
    {
        vector<int> Rows;
        for(int j = 1; j < n; ++j)
        {
            Rows.push_back(bfs(i,j,n));
        }
        answer.push_back(Rows);
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
