class Solution {
public:
    //mid time me kitne workers kaam kar sakte hai
    // int isPossible(vector<int>& arr,int mid){
    //     int paintTime=0;
    //     int worker=1;
    //     for(int i=0;i<arr.size();i++){
    //         if(paintTime + arr[i] <= mid){
    //             paintTime += arr[i];
    //         }
    //         else{
    //             worker++;
    //             paintTime = arr[i];
    //         }
    //     }
    //     return worker;
    // }

    int isPossible(vector<int>& arr,int mid, int k){
        int paintTime=0;
        int worker=1;
        for(int i=0;i<arr.size();i++){
            if(paintTime + arr[i] <= mid){
                paintTime += arr[i];
            }
            else{
                worker++;
                paintTime = arr[i];
                if(worker > k) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& arr, int k) {
        int s = *max_element(arr.begin(),arr.end());
        int e = accumulate(arr.begin(),arr.end(),0);
        
        int ans = 0;
        while(s<=e){
            int mid=s+(e-s)/2;
            // int totalWorkers = isPossible(arr,mid);
            // if(totalWorkers <= k){
            //     e=mid-1;
            // }
            if(isPossible(arr, mid, k)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s=mid+1;
            }
        }
        return s;
    }
};