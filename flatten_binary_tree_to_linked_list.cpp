class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        if(root -> left) {
            TreeNode * tmp = root -> left;
            while(tmp -> right != NULL) {
                tmp = tmp -> right;
            }
            tmp -> right = root -> right;
            root -> right = root -> left;
            root -> left = NULL;
        }
        flatten(root -> right);
    }
};