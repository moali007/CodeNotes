class Solution {
public:
    
    int digitSum(int num){
        int sum = 0;

        while(num > 0){
            int d = num % 10;
            num = num / 10;
            sum += d;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {
        int mini = 1e9;

        for(int num : nums){
            mini = min(mini, digitSum(num));
        }

        return mini;
    }
};