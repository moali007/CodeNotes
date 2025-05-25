class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();

        int cnt = 0;

        unordered_map<string, int> mp;

        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        
        int isFirstOdd = 0;

        for(int i=0;i<n;i++){
            string curr = words[i];
            string rev = curr;
            reverse(rev.begin(), rev.end());

            if(curr == rev){
                int freq = mp[curr];
                mp.erase(curr);
                if(freq % 2 == 0){ //ex: "aa" occurs 4 times
                    cnt += freq * 2;
                }
                else if(freq % 2 != 0){
                    if(isFirstOdd == 0){
                        cnt += freq * 2;
                        isFirstOdd = 1;
                    }
                    else{
                        cnt += (freq-1) * 2;
                    }
                }
            }

            else if(mp.find(rev) != mp.end()){
                int curr_freq = mp[curr]; 
                int rev_freq = mp[rev]; 

                int mini = min(curr_freq, rev_freq);
                cnt += mini * 4;

                mp.erase(curr);
                mp.erase(rev);
            }

            // if(curr == rev){
            //     if(curr_freq % 2 == 0){
            //         cnt += (curr_freq)*2;
            //     }
            //     else{
            //         if(isFirstOdd == 0){
            //             cnt += (curr_freq)*2;
            //             isFirstOdd = 1;
            //         }
            //         else{
            //             cnt += (curr_freq - 1)*2;
            //         }
            //     }
            // }
            // else if(curr != rev){
            //     if(mp.find(rev) != mp.end()){
            //         int rev_freq = mp[rev];

            //         cnt += (min(curr_freq, rev_freq)) * 4;
            //         mp.erase(curr);
            //         mp.erase(rev);
            //     }
            // }
        }

        return cnt;
    }
};