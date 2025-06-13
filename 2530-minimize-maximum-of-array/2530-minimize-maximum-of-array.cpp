class Solution {
public:
    
    bool isPossible(vector<int> &nums, int expectedMax){
        int n = nums.size();
        vector<long long> arr(nums.begin(), nums.end());

        for(int i=0 ; i < n-1 ; i++){
            if(arr[i] > expectedMax){
                return false;
            }

            long long buffer = expectedMax - arr[i];
            arr[i+1] = arr[i+1] - buffer;
        }

        return arr[n-1] <= expectedMax;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        int result = 0;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(isPossible(nums, mid)){
                result = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return result;
    }
};