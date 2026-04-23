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

    TreeNode* build(vector<int>& preorder,int &i,int min,int max){
        //bc
        if(i >= preorder.size()){
            return NULL;
        }

        TreeNode* root=NULL;
        if(preorder[i] > min && preorder[i] < max){
            root=new TreeNode(preorder[i++]);

            root->left=build(preorder,i,min,root->val);
            root->right=build(preorder,i,root->val,max);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min=INT_MIN;
        int max=INT_MAX;
        int i=0;
        TreeNode* root=build(preorder,i,min,max);
        return root;
    }
};