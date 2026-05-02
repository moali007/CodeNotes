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
    TreeNode* solve(int &idx, vector<int>& preorder, int start, int end, unordered_map<int, int> &mp){
        if(start > end){
            return NULL;
        }

        int rootVal = preorder[idx];
        int i = mp[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        idx++;

        root->left = solve(idx, preorder, start, i-1, mp);
        root->right = solve(idx, preorder, i+1, end, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }

        int idx = 0;
        return solve(idx, preorder, 0, n-1, mp);
    }
};