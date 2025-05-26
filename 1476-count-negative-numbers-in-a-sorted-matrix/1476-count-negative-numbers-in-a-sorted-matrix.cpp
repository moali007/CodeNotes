class Solution {
public:
    
    int BS(vector<int> &arr){
        int s = 0;
        int e = arr.size() - 1;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr[mid] >= 0){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return s;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int neg = 0;

        for(auto column : grid){
            sort(column.begin(), column.end());

            // int neg_elements = lower_bound(column.begin(), column.end(), 0) - column.begin();
            // neg += neg_elements;
            neg += BS(column);
        }

        return neg;
    }
};