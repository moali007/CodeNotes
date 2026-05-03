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

            if(curr == NULL) s.append("#,");
            else s.append(to_string(curr->val) + ',');

            if(curr != NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        s.pop_back(); //removes last comma
        cout<<"Sealize string = "<<s<<endl;
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
            TreeNode* curr = q.front();
            q.pop();
            
            //left
            getline(ss, s, ',');
            if(s == "#"){
                curr->left = NULL;
            }else{
                curr->left = new TreeNode(stoi(s));
                q.push(curr->left);
            }

            //right
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
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));