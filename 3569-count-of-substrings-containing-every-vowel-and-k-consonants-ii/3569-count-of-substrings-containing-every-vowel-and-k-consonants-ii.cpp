class Solution {
public:
   
   int n;
  
    bool isVowel(char &ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='u' || ch=='o';
    }

    long long f(string &s, int k){
        
        unordered_map<char, int> mp;
        int consonantCnt = 0;
        long long count = 0;

        int i=0,j=0;

        while(j < n){
            if(isVowel(s[j])){
                mp[s[j]]++;
            }else{
                consonantCnt++;
            }

            while(consonantCnt > k && mp.size() == 5){
                if(isVowel(s[i])){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                }else{
                    consonantCnt--;
                }
                i++;
            }

            count += (j-i+1);

            j++;
        }

        return count;
    }

    long long countOfSubstrings(string word, int k) {
        n = word.length();
        
        return f(word, k) - f(word, k-1);
        
    }
};