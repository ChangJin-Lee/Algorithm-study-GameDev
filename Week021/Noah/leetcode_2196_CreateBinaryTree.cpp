/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* map[100001] = {};
        bool child[100001] = {};
        
        for (auto& d : descriptions) {
            if (map[d[0]] == nullptr) {
                map[d[0]] = new TreeNode(d[0]);
            }

            TreeNode* node;
            
            if (map[d[1]] == nullptr) {
                node = new TreeNode(d[1]);
            } else {
                node = map[d[1]];
            }

            
            if (d[2] == 1) {
                map[d[0]]->left = node;
            } else {
                map[d[0]]->right = node;
            
            }
            
            map[node->val] = node;
            child[d[1]] = true;
        }
        
        for (auto& d : descriptions)
            if (child[d[0]] == false) {
                return map[d[0]];
            }
        
        return nullptr;
    }
};