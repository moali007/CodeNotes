class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();

        vector<int> ans;

        for(int i=0;i<n;i++){
            string word = words[i];
            set<char> st;
            for(char ch : word){
                st.insert(ch);
            }
            if(st.count(x)) ans.push_back(i);
        }

        return ans;
    }
};