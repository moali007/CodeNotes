class Solution {
public:
    
    TreeNode* build(vector<int>& preorder, int &i, int min, int max){
        if(i >= preorder.size()){
            return NULL;
        }
        
        TreeNode* curr = NULL;
        if(preorder[i] > min and preorder[i] < max){
            curr = new TreeNode(preorder[i++]);

            curr->left = build(preorder, i, min, curr->val);
            curr->right = build(preorder, i, curr->val, max);
        }

        return curr;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

       int i = 0;
       int min = INT_MIN;
       int max = INT_MAX;
       return build(preorder, i, min, max); 
    }
};