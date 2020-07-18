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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode * ans = NULL;
        auto func = [&](TreeNode * root, int val, auto &func) -> void {
            if(!root) {
                return;
            }
            if(root -> val == val) {
                ans = root;
                return;
            }
            if(root -> val <= val) {
                func(root -> right, val, func);
            } else {
                func(root -> left, val, func);
            }
        };
        
        func(root, val, func);
        return ans;
    }
};