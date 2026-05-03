/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();

            if(curr == NULL) s += "#,";
            else s += to_string(curr->val) + ',';

            if(curr != NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream ss(data);
        string s;
        getline(ss, s, ',');
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();

            getline(ss, s, ',');
            if(s == "#"){
                curr->left = NULL;
            }else{
                curr->left = new TreeNode(stoi(s));
                q.push(curr->left);
            }

            getline(ss, s, ',');
            if(s == "#"){
                curr->right = NULL;
            }else{
                curr->right = new TreeNode(stoi(s));
                q.push(curr->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;