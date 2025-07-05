class Solution {
public:
    int findLucky(vector<int>& arr) {
        int arr1[501]={0};
        for(int i = 0; i<arr.size();i++){
            arr1[arr[i]]++;
        }
        int ans =-1;
        for(int i = 1; i<501;i++){
            if(arr1[i]==i){
                ans=i;
            }
        }
        return ans;
        }
    
};