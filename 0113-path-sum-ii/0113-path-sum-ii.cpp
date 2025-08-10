class Solution {
public:
    vector<vector<int>> ans;
    void solve(TreeNode* root, int sum, vector<int> v){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                v.push_back(root->val);
                ans.push_back(v);
            }
            return;
        }
        
        v.push_back(root->val);
        solve(root->left, sum - root->val, v);
        solve(root->right, sum - root->val, v);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;

        solve(root, targetSum, v);

        return ans;
    }
};