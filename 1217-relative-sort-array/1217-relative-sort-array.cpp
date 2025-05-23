class Solution {
public:
    vector<int> relativeSortArray(vector<int>& A1, vector<int>& A2) {
        int N = A1.size();
        int M = A2.size();
        unordered_map<int, int> mp;
        for(int i=0;i<N;i++){
            mp[A1[i]]++;
        }
        
        vector<int> ans;
        
        for(int i=0;i<M;i++){
            int num = A2[i];
            int freq = mp[A2[i]];
            
            while(freq--){
                ans.push_back(num);
            }
        }
        
        sort(A1.begin(), A1.end());
        set<int> st(ans.begin(), ans.end());
        
        for(int i=0;i<N;i++){
            if(st.find(A1[i]) == st.end()){
                ans.push_back(A1[i]);
            }
        }
        
        return ans;
    }
};