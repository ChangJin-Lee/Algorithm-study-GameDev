#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countLuck' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY matrix
 *  2. INTEGER k
 */
 
 int bfs(vector<string> matrix)
 {
    int n = matrix.size();
    int m = matrix[0].length();
    pair<int,int> StartingPosition;
    pair<int,int> PortkeyPosition;
    queue<tuple<int,int,vector<pair<int,int>>>> q;
    vector<vector<bool>> visited(n, vector<bool>(m,false))
;    
    vector<pair<int,int>> Movable = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    vector<pair<int,int>> paths;
    int answer = 0;
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(matrix[i][j] == 'M')
            {
                StartingPosition = {i,j};
            }
            else if(matrix[i][j] == '*')
            {
                PortkeyPosition = {i,j};
            }
        }
    }
    
    q.push({StartingPosition.first, StartingPosition.second, {StartingPosition}});
    visited[StartingPosition.first][StartingPosition.second] = true;
    
    while(!q.empty())
    {
        int cx = get<0>(q.front());
        int cy = get<1>(q.front());
        vector<pair<int,int>> cp = get<2>(q.front());
        q.pop();
        
        for(pair<int,int> NextMove : Movable)
        {
            int nx = cx + NextMove.first;
            int ny = cy + NextMove.second;
            vector<pair<int,int>> np = cp;
            
            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    if(matrix[nx][ny] == '.')
                    {
                        np.push_back({nx,ny});
                        q.push({nx,ny,np});
                    }
                    else if(matrix[nx][ny] == '*')
                    {
                        paths = np;
                        break;
                    }
                }
            }
        }
    }
    
    for(pair<int,int> path : paths)
    {
        int x = path.first;
        int y = path.second;
        int Count = 0;
        
        if(matrix[x][y] == 'M')
        {
            Count = 1;
        }
        
        for(pair<int,int> NextMove : Movable)
        {
            int nx = x + NextMove.first;
            int ny = y + NextMove.second;
            
            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(matrix[nx][ny] == '.' || matrix[nx][ny] == 'M' || matrix[nx][ny] == '*')
                {
                    Count++;
                }
            }
        }
        
        if(Count > 2)
        {
            answer++;
        }
    }
    return answer;
 }

string countLuck(vector<string> matrix, int k) {
    if(bfs(matrix) == k)
    {
        return "Impressed";
    }
    else
    {
        return "Oops!";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        string k_temp;
        getline(cin, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        string result = countLuck(matrix, k);

        fout << result << "\n";
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
