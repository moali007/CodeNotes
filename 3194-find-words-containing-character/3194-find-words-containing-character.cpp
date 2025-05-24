class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();

        vector<int> ans;

        // for(int i=0;i<n;i++){
        //     string word = words[i];
        //     bool present = false;
        //     for(char ch : word){
        //         if(ch == x) present = true;
        //     }
        //     if(present == true) ans.push_back(i);
        // }
        
        auto lambda = [&x](char ch){
            return ch == x;
        };

        for(int i=0;i<n;i++){
            string word = words[i];

            if(any_of(word.begin(), word.end(), lambda) == true){
                ans.push_back(i);
            }
        }

        return ans;
    }
};