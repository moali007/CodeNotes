class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int n = d.size();

        vector<pair<double, int>> arr;

        for(auto it : d){
            int l = it[0];
            int b = it[1];

            double diag = sqrt(l*l + b*b);
            int area = l * b;

            arr.push_back({diag, area});
        }
        
        sort(arr.rbegin(), arr.rend());

        for(int i = 0; i<arr.size();i++){
            cout<<arr[i].first<<" "<<arr[i].second<<endl;
        }

        return arr[0].second;
    }
};