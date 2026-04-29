/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left){
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(root, parent_track);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        int level = 0;
        q.push(target);
        vis[target] = true;

        while(!q.empty()){
            int size = q.size();
            if(level == k) break;
            level++;

            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left and !vis[curr->left]){
                    vis[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right and !vis[curr->right]){
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
                if(parent_track[curr] and !vis[parent_track[curr]]){
                    vis[parent_track[curr]] = true;
                    q.push(parent_track[curr]);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};