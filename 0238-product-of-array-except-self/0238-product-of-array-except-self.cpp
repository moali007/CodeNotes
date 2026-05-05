class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixProduct(n);
        prefixProduct[0] = 1;

        for(int i=1;i<n;i++){
            prefixProduct[i] = prefixProduct[i-1] * arr[i-1];
        }

        vector<int> suffixProduct(n);
        suffixProduct[n-1] = 1;

        for(int i=n-2;i>=0;i--){
            suffixProduct[i] = suffixProduct[i+1] * arr[i+1];
        }

        vector<int> ans(n);

        for(int i=0;i<n;i++){
            ans[i] = prefixProduct[i] * suffixProduct[i];
        }

        return ans;
    }
};