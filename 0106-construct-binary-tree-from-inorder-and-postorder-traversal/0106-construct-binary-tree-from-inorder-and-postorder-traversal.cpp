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
    
    TreeNode* solve(int &idx, int start, int end, vector<int>& postorder, unordered_map<int, int>&mp){
        if(start > end){
            return NULL;
        }

        int rootVal = postorder[idx];
        TreeNode* root = new TreeNode(rootVal);
        int i = mp[rootVal];
        idx--;

        root->right = solve(idx, i+1, end, postorder, mp);
        root->left = solve(idx, start, i-1, postorder, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        unordered_map<int, int> mp; // store inorder mappings
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        
        int idx = n-1;
        return solve(idx, 0, n-1, postorder, mp);
    }
};