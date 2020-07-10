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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        
        bool flag = 0;
        vector < vector < int > > ans;
        stack < TreeNode * > st1;
        stack < TreeNode * > st2;
        st1.push(root);
        
        while(!st1.empty()) {
            vector < int > temp;
    
            while(!st1.empty()) {
                TreeNode * curr = st1.top();
                st1.pop();
                temp.push_back(curr -> val);
                if(!flag) {
                    if(curr -> left) st2.push(curr -> left);
                    if(curr -> right) st2.push(curr -> right);
                } else {
                    if(curr -> right) st2.push(curr -> right);
                    if(curr -> left) st2.push(curr -> left);
                }
            }
            flag = !flag;
            swap(st1, st2);
            ans.push_back(temp);
        }
        return ans;
    }
};