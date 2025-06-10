class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        vector<int> nge2(n); //next greater element of nums2
         
        stack<int> st;
        unordered_map<int, int> mp; //{nums2[i] - nge2[i]}

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            nge2[i] = st.empty() ? -1 : st.top();
            mp[nums2[i]] = nge2[i];

            st.push(nums2[i]);
        }

        int m = nums1.size();
        vector<int> nge1(m);
        for(int i=0;i<m;i++){
            nge1[i] = mp[nums1[i]];
        }

        return nge1;
    }
};