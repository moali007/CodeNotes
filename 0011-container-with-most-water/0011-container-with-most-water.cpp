class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int maxArea = 0;

        int i=0,j=n-1;

        while(i < j){
            int area = min(height[i], height[j]) * (j-i);
            maxArea = max(maxArea, area);

            if(height[i] <= height[j]) i++;
            else j--;
        }

        return maxArea;
    }
};