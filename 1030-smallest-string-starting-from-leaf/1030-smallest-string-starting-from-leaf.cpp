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
    vector<string> s;
    void solve(TreeNode* root, string curr){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            char ch = root->val + 'a';
            curr = (ch) + curr;
            s.push_back(curr);
            return;
        }
        
        char ch = root->val + 'a';
        solve(root->left, ch + curr);
        solve(root->right, ch + curr);
    }

    string smallestFromLeaf(TreeNode* root) {
        string curr = "";
        solve(root, curr);

        sort(s.begin(), s.end());

        return s[0];
    }
};