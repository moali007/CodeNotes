class Solution {
public:
    bool isValid(string word) {
        int n = word.length();

        if(n < 3) return false;
        int vowel = 0;
        int consonant = 0;
        int digit = 0;

        for(char ch : word){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ) vowel++;
            
            else if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) consonant++;
            
            else if(isdigit(ch)) digit++;

            else return false;

        }

        return (vowel > 0 && consonant > 0);
    }
};