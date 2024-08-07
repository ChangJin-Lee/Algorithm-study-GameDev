#include <bits/stdc++.h>

using namespace std;

vector<int> value;
int tot, best;
vector<vector<int>> v;
vector<bool> visited;
vector<int> sum;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */
 
int dfs(int node)
{
    int ret = 0;
    visited[node] = true;
    int sz = (int)v[node].size();
    for (int i = 0; i < sz; i++)
    {
        int next = v[node][i];
        if (!visited[next])
            ret += dfs(next);
    }
    return sum[node] = value[node] + ret;
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    int n = data.size();
    best = INT_MAX;
    tot = 0;

    value.assign(n + 1, 0);
    visited.assign(n + 1, false);
    sum.assign(n + 1, 0);
    v.assign(n + 1, vector<int>());

    for (int i = 1; i <= n; i++)
    {
        value[i] = data[i - 1]; // Adjust for 1-based indexing
        tot += value[i];
    }

    for (vector<int> edge : edges)
    {
        int a = edge[0];
        int b = edge[1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    dfs(1); // Start DFS from node 1

    for (int i = 2; i <= n; i++) // Check sums from node 2 to n (as node 1 is root)
    {
        int diff = abs(tot - sum[i] - sum[i]);
        if (diff < best)
        {
            best = diff;
        }
    }

    return best;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split(rtrim(data_temp_temp));

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);
        data[i] = data_item;
    }

    vector<vector<int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        edges[i].resize(2);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);
            edges[i][j] = edges_row_item;
        }
    }

    int result = cutTheTree(data, edges);

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
