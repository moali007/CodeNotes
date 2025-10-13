class Solution {
public:
    
    bool checkAnagram(string s, string t){
        vector<int> freq(26, 0);

        for(char ch : s){
            freq[ch - 'a']++;
        }
        for(char ch : t){
            freq[ch - 'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq[i] != 0) return false;
        }

        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> ans;
        ans.push_back(words[0]);

        // int i=1;
        // while(i < n){
        //     string prev = words[i-1];
        //     string curr = words[i];

        //     if(checkAnagram(prev, curr) == true){
        //         i++;
        //     }
        //     else{
        //         ans.push_back(curr);
        //         i++;
        //     }
        // }

        for(int i=1;i<n;i++){
            string prev = words[i-1];
            string curr = words[i];
            
            if(checkAnagram(prev, curr) == false){
                ans.push_back(curr);
            }

        }

        return ans;
    }
};