class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans=0;
        int prod=1;
        int len=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                len=0;
                prod=1;
                continue;
            }
            if(nums[i]>0)
                prod*=1;
            else if(nums[i]<0)
                prod*=-1;
            len++;
            if(prod>0)
            {
                ans = max(ans,len);
            }
        }
        
        len=0;
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==0)
            {
                len=0;
                prod=1;
                continue;
            }
            if(nums[i]>0)
                prod*=1;
            else if(nums[i]<0)
                prod*=-1;
            len++;
            if(prod>0)
            {
                ans = max(ans,len);
            }
        }

        return ans;
    }
};