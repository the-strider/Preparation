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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        function < int(TreeNode *) > dfs = [&](TreeNode * root) {
            if(root == NULL) {
                return 0;
            }
            int a = max(dfs(root -> left), 0);
            int b = max(dfs(root -> right), 0);
            ans = max(ans, a + b + root -> val);
            return max(a, b) + root -> val;
        };
        
        dfs(root);
        return ans;
    }
};