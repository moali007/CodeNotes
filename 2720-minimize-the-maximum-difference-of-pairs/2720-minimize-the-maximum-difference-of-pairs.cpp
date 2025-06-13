class Solution {
public:
    
    bool isPossible(vector<int>& nums, int mid, int p){
        int n = nums.size();
        int pairs = 0;
        int i=0;
        while(i < n-1){
            if(nums[i+1] - nums[i] <= mid){
                pairs++;
                i+=2;
            }
            else{
                i+=1;
            }
        }

        return pairs >= p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int s = 0;
        int e = nums[n-1] - nums[0];

        int ans = INT_MAX;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(isPossible(nums, mid, p)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }
};