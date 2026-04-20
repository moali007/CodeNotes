class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int i = 0, j = n - 1;
        int left = 0;

        while(i < j){
            if(colors[i] != colors[j]){
                left = j - i;
                break;
            }else{
                j--;
            }
        }

        int right = 0;
        i = 0, j = n-1;
        while(i < j){
            if(colors[i] != colors[j]){
                right = j - i;
                break;
            }else{
                i++;
            }
        }

        return max(left, right);
        
    }
};