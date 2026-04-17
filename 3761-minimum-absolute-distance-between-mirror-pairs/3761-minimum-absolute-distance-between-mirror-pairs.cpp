class Solution {
public:
    int reverse(int num){
        int rev = 0;
        while(num > 0){
            int d = num % 10;
            num = num / 10;
            rev = rev * 10 + d;
        }

        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp; //{val, index}
        int mini = 1e9;
        for(int i = 0; i < n; i++){
            if(mp.count(nums[i])){
                mini = min(mini, i - mp[nums[i]]);
            }

            int revNum = reverse(nums[i]);
            mp[revNum] = i;
        }
        

        return mini == 1e9 ? -1 : mini;
    }
};