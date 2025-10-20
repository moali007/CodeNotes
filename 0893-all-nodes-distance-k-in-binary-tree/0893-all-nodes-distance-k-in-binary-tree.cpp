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
    
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentTrack){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();

            if(curr->left){
                parentTrack[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parentTrack[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        markParent(root, parentTrack);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            if(level == k) break;
            level++;

            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front(); q.pop();

                if(curr->left and !vis[curr->left]){
                    vis[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right and !vis[curr->right]){
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
                if(parentTrack[curr] and !vis[parentTrack[curr]]){
                    vis[parentTrack[curr]] = true;
                    q.push(parentTrack[curr]);
                }
            }
        }

        vector<int> result;
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            result.push_back(curr->val);
        }

        return result;
    }
};