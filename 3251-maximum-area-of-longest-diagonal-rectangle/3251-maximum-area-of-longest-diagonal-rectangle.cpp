class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int n = d.size();

        double maxDiagonal = 0;
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            int l = d[i][0];
            int b = d[i][1];

            double diag = sqrt(l*l + b*b);
            int area = l*b;

            if((diag > maxDiagonal) || (diag == maxDiagonal and area>maxArea)){
                maxDiagonal = diag;
                maxArea = area;
            }
        }

        return maxArea;


    }
};