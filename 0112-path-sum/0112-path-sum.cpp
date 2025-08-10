class Solution {
public:
    
    bool solve(TreeNode* root, int sum){
        if(root == NULL){
            return false;
        }

        if(root->left == NULL && root->right == NULL){
            return root->val == sum;
        }

        bool a = solve(root->left, sum - root->val);
        bool b = solve(root->right, sum - root->val);
        return a || b;

    }

    bool hasPathSum(TreeNode* root, int sum) {
        return solve(root, sum);
    }
};