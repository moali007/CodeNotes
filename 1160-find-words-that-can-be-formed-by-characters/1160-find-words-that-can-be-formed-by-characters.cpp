class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;

        for(char ch : chars){
            mp[ch]++;
        }

        int sum = 0;

        for(string word : words){
            unordered_map<char, int> mp1;

            for(char ch : word){
                mp1[ch]++;
            }

            bool valid = true;;

            for(auto it : mp1){
                char ch = it.first;
                if(mp.find(ch) == mp.end() || mp[ch] < mp1[ch]){
                    valid = false; 
                    break;
                }

            }

            if(valid){ 
                sum += word.length(); 
            }
        }

        return sum;
    }
};