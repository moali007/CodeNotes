class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;

        for(int i=0;i<n-3;i++){
            if(i>0 && arr[i] == arr[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j-1>i && arr[j] == arr[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k < l){
                    long long sum = arr[i];
                    sum+=arr[j];
                    sum+=arr[k];
                    sum+=arr[l];

                    if(sum > target){
                        l--;
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                        ans.push_back(temp);
                        k++,l--;
                        while(k<l && arr[k] == arr[k-1]) k++;
                        while(k<l && arr[l] == arr[l+1]) l--;

                    }
                }
            }
        }
        return ans;
    }
};