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
    int n;
    
    TreeNode* f(vector<int>& preorder, int &i, int min, int max){
        if(i >= n){
            return NULL;
        }

        TreeNode* root = NULL;
        if(preorder[i] > min and preorder[i] < max){
            root = new TreeNode(preorder[i++]);

            root->left = f(preorder, i, min, root->val);
            root->right = f(preorder, i, root->val, max);
        }
        
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size();

        int min = INT_MIN;
        int max = INT_MAX;
        int i = 0;

        return f(preorder, i, min, max);
    }
};