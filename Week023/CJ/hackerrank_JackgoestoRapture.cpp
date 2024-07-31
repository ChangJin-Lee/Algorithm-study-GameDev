#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getCost' function below.
 *
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

void getCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    vector<vector<pair<int,int>>> graph(g_nodes, vector<pair<int,int>>());
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq; // edge, node
    vector<int> distance(g_nodes, 10000001);
    
    for(int i = 0; i < g_from.size(); i++)
    {
        graph[g_from[i]-1].push_back({g_to[i]-1, g_weight[i]});
        graph[g_to[i]-1].push_back({g_from[i]-1, g_weight[i]});
    }

    pq.push({0, 0});
    
    while(!pq.empty())
    {
        int curNode = pq.top().second;
        int curEdge = pq.top().first;
        pq.pop();
        
        for(int i = 0; i < graph[curNode].size(); i++)
        {
            int nextNode = graph[curNode][i].first;
            int nextEdge = graph[curNode][i].second;
            int nextEdgediff = max(0,nextEdge-curEdge);
            
            if(nextEdge == 0) continue;
            
            if(distance[nextNode] > curEdge + nextEdgediff)
            {
                distance[nextNode] = curEdge + nextEdgediff;
                pq.push({curEdge + nextEdgediff,nextNode});
            }
        }
    }
    
    if(distance[g_nodes-1] == 10000001)
        cout << "NO PATH EXISTS";
    else
        cout << distance[g_nodes-1];
}

int main()
{
    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    getCost(g_nodes, g_from, g_to, g_weight);

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
