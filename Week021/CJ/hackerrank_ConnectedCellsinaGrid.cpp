#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'connectedCell' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */
 
const vector<pair<int, int>> directions = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0},
    {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
};

int bfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
    int n = matrix.size();
    int m = matrix[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    int size = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        size++;

        for (const pair<int,int> direction : directions) {
            int nx = cx + direction.first;
            int ny = cy + direction.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && matrix[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return size;
}

int connectedCell(vector<vector<int>> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int maxSize = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                int size = bfs(matrix, visited, i, j);
                maxSize = max(maxSize, size);
            }
        }
    }

    return maxSize;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<int>> matrix(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

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
