class Solution {
public:
//BRUTE FORCE
    // int majorityElement(vector<int>& arr) {
    //     int n=arr.size();

    //     for(int i=0;i<n;i++){
    //         int count=0;
    //         for(int j=0;j<n;j++){
    //             if(arr[i] == arr[j])
    //              count++;
    //         }
    //         if(count > n/2)
    //          return arr[i];
    //     }
    //     return -1;
        
    // }
    

    //better - TC - O(NlogN) + O(N)  SC-O(N)
    // int majorityElement(vector<int>& arr) {
    //     int n=arr.size();
    //     map<int,int> mp; //{element,count}
    //     for(int i=0;i<n;i++){
    //         mp[arr[i]]++;
    //     }

    //     for(auto it : mp){
    //         if(it.second > n/2)
    //          return it.first;
    //     }
    //     return -1;
    // }
    
    //BEST TC O(N+N)  SC - O(1)
    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        int ele;
        int cnt1=0;
        for(int i=0;i<n;i++){
            //finding majority element
            if(cnt1 == 0){
                cnt1=1;
                ele=arr[i];
            }
            else if(arr[i] == ele){
                cnt1++;
            }
            else
                cnt1--;
        }

        //now checking if majority element occurs more than n/2 
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(arr[i] == ele)
             cnt2++;
        }
        if(cnt2 > n/2){
            return ele;
        }
        return -1;

    }
};