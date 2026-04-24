class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key){
            return helper(root);
        }

        TreeNode* dummy = root;
        while(root){
            if(root->val > key){
                if(root->left and root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
                if(root->right and root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }

        return dummy;
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        
        TreeNode* rootRight = root->right;
        TreeNode* rightChild = lastRight(root->left);
        rightChild->right = rootRight;
        
        return root->left;
    }

    TreeNode* lastRight(TreeNode* root){
        TreeNode* curr = NULL;
        while(root){
            curr = root;
            root = root->right;
        }

        return curr;
    }
};