struct Node{
    bool isEndOfWord;
    Node* children[10];
};

class Solution {
public:
    
    Node* getNode(){
        Node* newNode = new Node();
        newNode->isEndOfWord = false;
        for(int i=0;i<10;i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(int num, Node* root){
        string word = to_string(num);

        Node* temp = root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            int idx = ch -'0';

            if(temp->children[idx] == NULL){
                temp->children[idx] = getNode();
            }
            temp = temp->children[idx];
        }

        temp->isEndOfWord = true;
    }

    int search(int num, Node* root) {
        string word = to_string(num);
        Node* temp = root;
        int length = 0;
        
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            int idx = ch - '0';

            if(temp->children[idx] != NULL){
                length++;
                temp = temp->children[idx];//temp aage badhao
            }
            else{
                break;
            }
        }
        
        return length;
    }


    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Node* root = getNode();

        for(int num : arr2){
            insert(num,root);
        }

        int result = 0;

        for(int num : arr1){
            result = max(result,search(num, root));
        }
        return result;
    }
};