class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();

        vector<int> nge(n);
        nge[n-1] = 0;
        stack<pair<int, int>> st;
        st.push({temp[n-1], n-1});

        for(int i = n-2; i >= 0; i--){
            while(!st.empty() and st.top().first <= temp[i]){
                st.pop();
            }

            nge[i] = st.empty() ? 0 : st.top().second;

            st.push({temp[i], i});
        }

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            if(nge[i] == 0) continue;
            else{
                ans[i] = nge[i] - i;
            }
        }

        return ans;

    }
};