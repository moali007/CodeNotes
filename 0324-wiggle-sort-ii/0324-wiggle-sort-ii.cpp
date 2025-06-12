class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // Step 1: Sort the array

        vector<int> result(n);  // Step 2: Create a result array

        int i = n - 1;
        int j = 1;

        // Step 3: Fill odd indices with largest elements
        while (j < n) {
            result[j] = nums[i];
            i--;
            j += 2;
        }

        // Step 4: Fill even indices with remaining elements
        j = 0;
        while (j < n) {
            result[j] = nums[i];
            i--;
            j += 2;
        }

        // Step 5: Copy result back to original array
        for (int i = 0; i < n; i++) {
            nums[i] = result[i];
        }
    }
};
