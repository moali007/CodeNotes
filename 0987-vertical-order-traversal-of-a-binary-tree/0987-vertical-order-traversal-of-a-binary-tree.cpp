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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q; //{node, {vertical, level}}
        map<int, map<int, multiset<int>>> mp; //{vertical, {level, elements at that level for that vertical}}

        q.push({root, {0, 0}});
        while(!q.empty()){
            auto p = q.front(); q.pop();

            TreeNode* curr = p.first;
            int v = p.second.first;
            int l = p.second.second;

            mp[v][l].insert(curr->val);

            if(curr->left) q.push({curr->left, {v-1, l+1}});
            if(curr->right) q.push({curr->right, {v+1, l+1}});
        }

        vector<vector<int>> ans;
        for(auto p : mp){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};