class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr;
        arr.push_back(nums[0]);

        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]) continue;

            arr.push_back(nums[i]);
        }

        int cnt = 0;
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) cnt++;
            else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) cnt++;
        }

        return cnt;
    }
};