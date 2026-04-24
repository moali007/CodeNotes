class Solution {
public:
    bool f(TreeNode* root, long left, long right){
        if(root == NULL) return true;

        if(root-> val > left and root->val < right and
           f(root->left, left, root->val) and f(root->right, root->val, right)){
            return true;
        }

        return false;
    }

    bool isValidBST(TreeNode* root) {
        long left = LONG_MIN;
        long right = LONG_MAX;

        return f(root, left, right);
    }
};