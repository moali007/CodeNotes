class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> ans(n);
        stack<pair<int, int>> st; //{temperatures[i], i}

        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }

            st.empty() ? ans[i] = 0 : ans[i] = st.top().second - i;

            st.push({temperatures[i], i});
        }

        // reverse(ans.begin(), ans.end());

        return ans;
    }
};