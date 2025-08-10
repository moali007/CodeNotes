class Solution {
public:
    int total = 0;
    
    void solve(TreeNode* root, int sum){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            sum = sum * 10 + root->val;
            total += sum;
            return;
        }

        solve(root->left, sum * 10 + root->val);
        solve(root->right, sum * 10 + root->val);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;

        solve(root, sum);

        return total;
    }
};