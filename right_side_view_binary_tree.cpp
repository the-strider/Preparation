class Solution {
public:
    vector<int> rightSideViewRecursive(TreeNode* root) {
        vector < int > ans;
        auto dfs = [&](TreeNode * root, int depth, auto &dfs) -> void {
            if(!root) {
                return;
            }
            if(depth == ans.size()) {
                ans.push_back(root -> val);
            }
            dfs(root -> right, depth + 1, dfs);
            dfs(root -> left, depth + 1, dfs);
        };
        dfs(root, 0, dfs);
        return ans;
    }Q
};