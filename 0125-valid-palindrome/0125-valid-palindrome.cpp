class Solution {
public:
    
    bool checkPalindrome(string str){
        int i=0;
        int j=str.length()-1;

        while(i < j){
            if(str[i] != str[j]){
                return false;
            }else{
                i++,j--;
            }
        }
        return true;
    }

    bool isPalindrome(string s) {

        string str = "";
        for(char ch : s){
            if(isalnum(ch)){//isalnum(ch) takes a char and returns true if the char is an alphabet or a digit 
                str += tolower(ch);
            }
        }
        
        return checkPalindrome(str);
    }
};