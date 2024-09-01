class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res;
        vector<int> path;
        
        dfs(candidates, 0, target, path, res);
        
        return res;
    }
    
    void dfs(vector<int>& candidates, int cur, int target, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0){
            res.push_back(path);
            return;
        }
        
        if (target < 0){
            return;
        }
        
        for (int i = cur; i < candidates.size(); i++) {
            if (i > cur && candidates[i] == candidates[i - 1]){
                continue;
            }
            
            path.push_back(candidates[i]);
            
            dfs(candidates, i + 1, target - candidates[i], path, res);
            
            path.pop_back();
        }
    }
};