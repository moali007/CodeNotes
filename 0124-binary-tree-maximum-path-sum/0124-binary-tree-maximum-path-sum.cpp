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
    int solve(TreeNode* root, int &maxSum) {
        if(root == NULL){
            return 0;
        }

        int leftAns = max(0, solve(root->left, maxSum));
        int rightAns = max(0, solve(root->right, maxSum));

        maxSum = max(maxSum, leftAns + rightAns + root->val);

        return root->val + max(leftAns, rightAns);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = -1e9;

        solve(root, maxSum);

        return maxSum;
    }
};

// curr node
// leftAns + rightAns + curr->val