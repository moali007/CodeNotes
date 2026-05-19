class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<int> freq(26, 0);
        for(char ch : words[0]){
            freq[ch - 'a']++;
        }


        for(int i = 1; i < words.size(); i++){
            string word = words[i];

            vector<int> curr(26, 0);
            for(char ch : word){
                curr[ch - 'a']++;
            }

            for(int i = 0; i < 26; i++){
                if(curr[i] == 0){
                    freq[i] = 0;
                }else{
                    freq[i] = min(freq[i], curr[i]);
                }
            }
        }

        vector<string> ans;

        for(int i = 0 ; i < 26; i++){
            if(freq[i] != 0){
                while(freq[i] > 0){
                    ans.push_back(string(1, i + 'a'));
                    freq[i]--;
                }
            }
        }

        return ans;
    }
};