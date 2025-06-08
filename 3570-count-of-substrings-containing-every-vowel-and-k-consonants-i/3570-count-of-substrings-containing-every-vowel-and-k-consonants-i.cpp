class Solution {
public:
    int n;
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    int f(string &word, int k){

        int i=0,j=0;
        int cnt = 0;
        int consonantCnt = 0;
        unordered_map<char, int> mp;

        while(j < n){
            if(isVowel(word[j])){
                mp[word[j]]++;
            }else{
                consonantCnt++;
            }

            while(consonantCnt > k && mp.size() >= 5){
                if(isVowel(word[i])){
                    mp[word[i]]--;
                    if(mp[word[i]] == 0) mp.erase(word[i]);
                }else{
                    consonantCnt--;
                }
                i++;
            }

            // if(mp.size() <= vowels && consonantCnt <= k){
                cnt += j-i+1;
            // }

            j++;
        }

        return cnt;
    }

    int countOfSubstrings(string word, int k) {
        n = word.length();
        
        int a = f(word, k); //substrings with vowels <= 5 && consonants <= k
        // int x = k-1<0 ? 0 : k-1;
        int b = f(word, k-1); //substrings with vowels <= 5 && consonants <= k

        return a - b;
    }
};