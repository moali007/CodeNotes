class Solution {
public:
    bool solve(int i, long long mul, int n, vector<int> &nums, long long target, unordered_set<int> &first) {
        if (i >= n) return false;    // index out of bound
        if (mul == target) return true; // current product equals target
        if (mul > target) return false; // we can never go back to smaller value

        bool take = solve(i + 1, mul * nums[i], n, nums, target, first); 
        // i + 1 :           move to next element
        // mul * nums[i] :   since we took current element, we multiplied it to previous product

        // if we got the target by taking current element we push current index in the set and return true
        if (take) { 
            first.insert(i); 
            return true; 
        }
        bool notTake = solve(i + 1, mul, n, nums, target, first); 
        // curr + 1 :   move to next element
        // mul :        since we did not take the current element, we pass the previous product to next call
        return notTake; 
    }
    
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size(); 
        unordered_set<int> first;
        if (solve(0, 1, n, nums, target, first)) { 
            if (first.size() == 0) return false;   

            long long part2 = 1; 
            for (int i = 0; i < n; i++) {  
                if (first.count(i)) continue; 
                part2 *= nums[i]; 
            } 
            if (part2 == target) return true; 
        }
        return false; 
    }
};