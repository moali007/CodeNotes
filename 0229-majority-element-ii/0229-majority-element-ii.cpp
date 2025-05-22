class Solution {
public:
    // vector<int> majorityElement(vector<int>& arr) {
    //     int n=arr.size();
    //     vector<int> ans;
    //     map<int,int> mp; //{element,count}
    //     for(int i=0;i<arr.size();i++){
    //         mp[arr[i]]++;
    //     }

    //     for(auto it : mp){
    //         if(it.second > n/3){
    //             ans.push_back(it.first);
    //         }
    //     }
    //     return ans;
    // }

    vector<int> majorityElement(vector<int>& arr) {
        int c1=0;
        int ele1;
        int c2=0;
        int ele2;
        int n=arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(c1==0 && arr[i] != ele2){
                c1=1;
                ele1=arr[i];
            }
            else if(c2 == 0 && arr[i] != ele1){
                c2=1;
                ele2=arr[i];
            }
            else if(arr[i] == ele1){
                c1++;
            }
            else if(arr[i] == ele2){
                c2++;
            }
            else{
                c1--,c2--;
            }
        }

        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(arr[i] == ele1){
                count1++;
            }
            else if(arr[i] == ele2){
                count2++;
            }
        }
        if(count1 > n/3)
         ans.push_back(ele1);
        if(count2 > n/3)
         ans.push_back(ele2); 

        return ans;
    }
};