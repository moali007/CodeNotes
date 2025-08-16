class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;

        int ans = 0;
        int i = 0;
        while(i+1 < s.length()){
            string str = "";
            str += s[i];
            str += s[i+1];

            if(str == "IV"){
                ans += 4;
                i += 2;
            }else if(str == "IX"){
                ans += 9;
                i += 2;
            }else if(str == "XL"){
                ans += 40;
                i += 2;
            }else if(str == "XC"){
                ans += 90;
                i += 2;
            }else if(str == "CD"){
                ans += 400;
                i += 2;
            }else if(str == "CM"){
                ans += 900;
                i += 2;
            }else{
                ans += mp[s[i]];
                i += 1;
            }
        }


        if(i < s.length()){
            ans += mp[s[i]];
        }
    

        return ans;

        
    }
};