#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int>  edge_cnt; 

        for(const vector<int> row : wall)
        {
            int pos = 0;

            for(int i = 0; i < row.size() - 1; ++i)
            {
                pos += row[i];
                edge_cnt[pos]++;
            }
        }

        int max_edge = 0;
        for(const auto& [pos, cnt] : edge_cnt)
        {
            max_edge = max(max_edge, cnt);
        }

        return wall.size() - max_edge;
    }
};