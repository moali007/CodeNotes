class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.length();

        vector<int> arr(26, -1);
        int cnt = 0;

        for(int i=0;i<n;i++){
            int idx = word[i] - 'a';

            if(arr[idx] != -1 && i-arr[idx]+1 >= 4){
                cnt++;

                for(int i=0;i<26;i++){
                    arr[i] = -1;
                }
            }
            else{
                if(arr[idx] == -1){
                    arr[idx] = i;
                }
            }
        }

        return cnt;
        
    }
};