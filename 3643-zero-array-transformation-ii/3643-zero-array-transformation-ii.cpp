class Solution {
public:
    int n;
    int Q;

    bool checkWithDiffArrTech(vector<int>& nums, vector<vector<int>>& queries, int k){
        vector<int> diff(n, 0);

        for(int i=0;i<=k;i++){//k queries tak check kar re
           
           int l = queries[i][0];
           int r = queries[i][1];
           int x = queries[i][2];

           diff[l] += x;
           if(r+1 < n)
             diff[r+1] -= x;
        }

        int cumSum = 0;
        for(int i=0;i<n;i++){
            cumSum += diff[i];

            diff[i] = cumSum;

            if(nums[i] - diff[i] > 0){
                return false; // k queries process karne par bhi 0 nahi hora
            }
        }

        return true;
    } 

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        Q = queries.size();

        auto lambda = [](int x){
            return x==0;
        };

        if(all_of(nums.begin(), nums.end(), lambda)){
            return 0; //already sab zero hai
        }

        // for(int i=0;i<Q;i++){
        //     if(checkWithDiffArrTech(nums, queries, i) == true){
        //         return i+1;
        //     }
        // }

        int s = 0;
        int e = Q-1;
        int k = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(checkWithDiffArrTech(nums, queries, mid) == true){
                k = mid + 1;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return k;
    }
};