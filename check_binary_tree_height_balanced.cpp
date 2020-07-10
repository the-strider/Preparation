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
    pair < int, bool > calc(TreeNode * root) {
        if(root == NULL) {
            return make_pair(0, 1);
        }
        pair < int, bool > a = calc(root -> left);
        if(a.second == false) return a;
        pair < int, bool > b = calc(root -> right);
        bool flag = (abs(a.first - b.first) <= 1);
        return make_pair(max(a.first, b.first) + 1, a.second & b.second & flag);
    } 

    bool isBalanced(TreeNode* root) {
        pair < int, bool > ans = calc(root);
        return ans.second;
    }
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool ok = 1;
        auto dfs = [&](TreeNode * root, auto &dfs) -> int {
            if(!root) return 0;
            int left = dfs(root -> left, dfs);
            int right = dfs(root -> right, dfs);
            if(abs(left - right) > 1) {
                ok = 0;
            }
            return max(left, right) + 1;
        };
        dfs(root, dfs);
        return ok;
        
    }
};