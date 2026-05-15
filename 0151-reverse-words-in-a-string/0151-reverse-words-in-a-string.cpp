class Solution {
public:
    string reverseWords(string s) {
        
        // reverse(s.begin(),s.end());
        // int n=s.length();
        // int i=0;
        // int l=0,r=0; // l ans r words ko reverse karege

        // while(i < n){
        //     while(i < n && s[i] != ' '){
        //         s[r++] = s[i++];
        //     }

        //     if(l < r){
        //         reverse(s.begin()+l,s.begin()+r);

        //         s[r] = ' ';
        //         r++;
        //         l=r;
        //     }

        //     i++;
        // }

        // return s.substr(0,r-1);

        

        //using stringstream tokenizer
        stringstream ss(s);
        string token = "";
        string res = "";

        while(ss >> token){
            res = token + " " + res;
        }

        // return res.substr(0,res.size()-1);
        res.pop_back();
        return res;

    }
};