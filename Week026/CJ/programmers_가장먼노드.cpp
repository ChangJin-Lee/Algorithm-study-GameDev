#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Search {
    vector<vector<int>> graphs;
    vector<int> distance;
public:
    Search(int n, const vector<vector<int>>& edges) : graphs(n), distance(n, 0) {
        for (const auto& edge : edges) {
            graphs[edge[0] - 1].push_back(edge[1] - 1);
            graphs[edge[1] - 1].push_back(edge[0] - 1);
        }
    }

    int bfs(int start) {
        queue<int> q;
        vector<bool> visited(graphs.size(), false);
        q.push(start);
        visited[start] = true;

        int maxDistance = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int next : graphs[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    distance[next] = distance[node] + 1;
                    maxDistance = max(maxDistance, distance[next]);
                    q.push(next);
                }
            }
        }
        return count(distance.begin(), distance.end(), maxDistance);
    }
};

int solution(int n, vector<vector<int>> edge) {
    Search search(n, edge);
    return search.bfs(0);
}

int main() {
    cout << solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}
