class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * ans = NULL;

        auto dfs = [&](TreeNode * root, auto &dfs) -> TreeNode* {
            if(!root) return NULL;
            if(root == p) {
                return root;
            }
            if(root == q) {
                return root;
            }
            TreeNode * a = dfs(root -> left, dfs);
            TreeNode * b = dfs(root -> right, dfs);
            if(a and b) return root;
            return a == NULL ? b: a;
        }; 
        return dfs(root, dfs);
    }
};