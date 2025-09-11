class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();

        string vowel = "";
        for(char ch : s){
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || 
             ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowel.push_back(ch);
            }
        }

        sort(vowel.begin(), vowel.end());
        int m = vowel.size();
        int j = 0;

        string t = s;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || 
             ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                t[i] = vowel[j++];
            }
            else t[i] = s[i];
        }

        return t;
    }
};