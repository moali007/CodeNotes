class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            int count = 0;

            // Case 1: Current person is taller than people in stack
            while (!st.empty() && heights[i] > st.top()) {
                count++;            // Current person can see this one
                st.pop();           // Remove shorter person — can't block anymore
            }

            // Case 2: Next greater or equal person exists
            if (!st.empty()) {
                count++;            // Can see this taller or equal-height person
            }

            ans[i] = count;
            st.push(heights[i]);             // Push current height for future comparisons
        }

        return ans;
    }
};