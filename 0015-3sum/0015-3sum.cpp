class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;

        for(int i=0;i<n-2;i++){
            if(i>0 && arr[i] == arr[i-1]) continue; //mtlb neeche ka code nahi chalega, i++ hoga
            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum = arr[i]+arr[j]+arr[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                } 
                else{
                    // vector<int> temp = {arr[i],arr[j],arr[k]};
                    // ans.push_back(temp);
                    ans.push_back({arr[i], arr[j], arr[k]});
                    j++,k--;
                    while(j<k && arr[j] == arr[j-1]) j++;
                    while(j<k && arr[k] == arr[k+1]) k--;
                }
            }

        }
        return ans;
    }
};