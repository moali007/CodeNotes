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
    
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
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

    TreeNode* findStartNode(TreeNode* root, int start){
        if(root == NULL) return NULL;

        if(root->val == start) return root;
        
        TreeNode* left = findStartNode(root->left, start);
        if(left) return left;
        return findStartNode(root->right, start);
    }


    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);

        TreeNode* startNode =  findStartNode(root, start);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(startNode);
        vis[startNode] = true;
        int cnt = 0;

        while(!q.empty()){
            int size = q.size();
            bool spread = false;
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front(); q.pop();

                if(curr->left && !vis[curr->left]){
                    spread = true;
                    vis[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right]){
                    spread = true;
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
                if(parent_track[curr] && !vis[parent_track[curr]]){
                    spread = true;
                    vis[parent_track[curr]] = true;
                    q.push(parent_track[curr]);
                }
            }
            if(spread == true) cnt++;
        }

        return cnt;

    }
};