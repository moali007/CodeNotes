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


    void solve(TreeNode* &root,vector<int> &ans){
        if(root==NULL)
        return;

        //LNR
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
       
        // vector<int>ans;
        // solve(root,ans);
        // return ans;

        //morris inorder traversal
        vector<int> inorder;
        TreeNode* curr = root;
        
        while(curr != NULL){
            if(curr->left == NULL){ // visit ki baari, then right
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* leftChild = curr->left;
                //go extreme right of leftChild
                while(leftChild->right != NULL){
                    leftChild = leftChild->right;
                }
                leftChild->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }

        return inorder;
    }
};