class Solution {
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](TreeNode * root, auto &dfs) -> int {
            if(!root) return 0;
            int left = dfs(root -> left, dfs);
            int right = dfs(root -> right, dfs);
            ans = max(ans, left + right);
            return max(left, right) + 1;
        };
        dfs(root, dfs);
        return ans;
    }
};