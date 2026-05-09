class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr = nums;
        for(int i = 0; i < n; i++){
            arr.push_back(nums[i]);
        }

        stack<int> st;

        vector<int> ans(n);

        for(int i = arr.size() - 1; i >= 0; i--){
            while(!st.empty() and st.top() <= arr[i]){
                st.pop();
            }

            if(i < n){
                ans[i] = st.empty() ? -1 : st.top();
            }

            st.push(arr[i]);
        }

        return ans;
    }
};