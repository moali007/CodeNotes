class Solution {
public:
    TreeNode* preorder(TreeNode* root, int start){
        if(root == NULL) return NULL;

        if(root->val == start) return root;

        TreeNode* left = preorder(root->left, start);
        if(left) return left;

        return preorder(root->right, start);
    }

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

    int amountOfTime(TreeNode* root, int start) {
        //get start node
        TreeNode* startNode = preorder(root, start);

        //mark parents
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(root, parent_track);

        unordered_map<TreeNode*, bool> vis;
        int time = 0;
        queue<TreeNode*> q;
        q.push(startNode);
        vis[startNode] = true;

        while(!q.empty()){
            int size = q.size();
            bool spread = false;

            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left and !vis[curr->left]){
                    spread = true;
                    vis[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right and !vis[curr->right]){
                    spread = true;
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
                if(parent_track[curr] and !vis[parent_track[curr]]){
                    spread = true;
                    vis[parent_track[curr]] = true;
                    q.push(parent_track[curr]);
                }
            }
            // if(spread == true) time++;
            time++;
        }
        return time-1;
    }
};