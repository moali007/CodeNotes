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
                while(leftChild->right){
                    leftChild = leftChild->right;
                }
                //attach rightmost to curr
                leftChild->right = curr;
                //move curr left and delete curr->left
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }else{
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }

        return inorder;
    }
};