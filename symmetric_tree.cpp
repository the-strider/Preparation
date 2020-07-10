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
    bool isSymmetric(TreeNode* root) {
        auto dfs = [&](TreeNode * r1, TreeNode * r2, auto &dfs) -> bool {
            if(!r1 and !r2) return true;
            if(!r1 or !r2) return false;
            
            bool res = (r1 -> val == r2 -> val);
            res &= dfs(r1 -> left, r2 -> right, dfs);
            res &= dfs(r1 -> right, r2 -> left, dfs);
            return res;
        };
        
        return dfs(root, root, dfs);
    }
};