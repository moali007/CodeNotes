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
    
    int solve(TreeNode* root, int &maxPathSum){
        if(root == NULL) return 0;

        int leftPathSum = max(0, solve(root->left, maxPathSum));
        int rightPathSum = max(0, solve(root->right, maxPathSum));

        maxPathSum = max(maxPathSum, root->val + leftPathSum + rightPathSum);

        return root->val + max(leftPathSum, rightPathSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        solve(root, maxPathSum);
        return maxPathSum;
    }
};

//maxPathSum = max(maxPathSum, node->val + leftPathSum + rightPathSum)
//return node->val + max(leftPathSum, rightPathSum)