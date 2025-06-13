class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int minDiff = 1e9;

        for(int i=1 ; i<n ; i++){
            minDiff = min(minDiff, arr[i] - arr[i-1]);
        }

        vector<vector<int>> result;
        
        for(int i=1 ; i<n ; i++){
            int diff = arr[i] - arr[i-1];

            if(diff == minDiff){
                result.push_back({arr[i-1], arr[i]});
            }
        }

        return result;
    }
};