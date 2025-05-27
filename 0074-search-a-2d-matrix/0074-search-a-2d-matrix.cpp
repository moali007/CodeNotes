class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(); //total rows
        int n=matrix[0].size(); //total cols

        int s=0;
        int e=m*n -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            int rowIndex = mid/n;
            int colIndex = mid%n;

            if(matrix[rowIndex][colIndex] == target){
                return true;
            }
            else if(matrix[rowIndex][colIndex] < target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
    }
};