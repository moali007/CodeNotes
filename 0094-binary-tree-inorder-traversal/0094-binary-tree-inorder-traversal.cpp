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
    //MORRIS INORDER TRAVERSAL
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;

        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* leftChild = curr->left;
                //go extreme right of leftChild node
                while(leftChild->right && leftChild->right != curr){
                    leftChild = leftChild->right;
                }
                //if thread not created yet, create it
                if(leftChild->right == NULL){
                    leftChild->right = curr;
                    curr = curr->left;
                }else{
                    //thread already exists, break it
                    leftChild->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }else{
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }

        return inorder;
    }
};