#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Island {
public:
    vector<vector<int>> map;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int rows, cols;

    Island(vector<string>& maps) {
        rows = maps.size();
        cols = maps[0].size();
        map.assign(rows, vector<int>(cols, 0));

        for (int y = 0; y < rows; ++y) {
            for (int x = 0; x < cols; ++x) {
                if (maps[y][x] != 'X') {
                    map[y][x] = maps[y][x] - '0';
                }
            }
        }
    }

    int dfs(int y, int x) {
        if (y < 0 || y >= rows || x < 0 || x >= cols || map[y][x] == 0)
            return 0;

        int sum = map[y][x];
        map[y][x] = 0;

        for (auto [dy, dx] : directions) {
            sum += dfs(y + dy, x + dx);
        }
        return sum;
    }

    vector<int> findDurations() {
        vector<int> result;
        for (int y = 0; y < rows; ++y) {
            for (int x = 0; x < cols; ++x) {
                if (map[y][x] != 0) {
                    result.push_back(dfs(y, x));
                }
            }
        }
        if (result.empty()) result.push_back(-1);
        sort(result.begin(), result.end());
        return result;
    }
};

vector<int> solution(vector<string> maps) {
    Island island(maps);
    return island.findDurations();
}
