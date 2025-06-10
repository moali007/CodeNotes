class Solution {
public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        int m = nums.length();

        //step1 : find dip index
        int dipIdx = -1;
        for(int i=m-1;i>=0;i--){
            if(i-1 >= 0 && nums[i] > nums[i-1]){
                dipIdx = i-1;
                break;
            }
        }

        if(dipIdx == -1){
            return -1;
        }

        else{
            //step2: find first element from end which is greater than dipElement and swap them
            for(int i=m-1;i>=dipIdx;i--){
                if(nums[i] > nums[dipIdx]){
                    swap(nums[i], nums[dipIdx]);
                    break;
                }
            }

            //step3: reverse nums from dipIdx+1 to end

            reverse(nums.begin()+dipIdx+1, nums.end());
        }

        int num = stol(nums);

        return (num > INT_MAX || num <= n) ? -1 : num;
    }
};