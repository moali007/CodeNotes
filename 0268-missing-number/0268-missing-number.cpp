class Solution {
public:
    // int missingNumber(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     int n=nums.size();
    //     int i;
    //     for(i=0;i<n;i++){
    //         if(nums[i] != i){
    //             return i;
    //         }
    //     }
    //     return i;
    // }

    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int xor1=0;

        for(int i=0;i<N;i++){
            xor1 = xor1 ^ nums[i];
        }

        int M = N + 1; //missing element + whole array
        int xor2=0;
        for(int i=0;i<=N;i++){
            xor2 = xor2 ^ i;
        }

        return xor2 ^ xor1;

    }
};