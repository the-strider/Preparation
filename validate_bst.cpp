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
using ll = long long;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        auto dfs = [&](TreeNode * root, ll low, ll high, auto &dfs) -> bool {
            if(root == NULL) {
                return true;
            }
            bool flag = 0;
            if(root -> val > low and root -> val < high) {
                flag = 1;
            }
            flag &= dfs(root -> left, low, root -> val, dfs);
            flag &= dfs(root -> right, root -> val, high, dfs);
            return flag;
        };
        
        return dfs(root, -1e12, 1e12, dfs);
    }
};