class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;

        int i = 0;

        while(i<n) {
            int l = i;
            int h = 0;
            vector<int> v;

            while (l >= 0 && h < m) {
                v.push_back(mat[l][h]);
                l--;
                h++;
            }

            if ((i % 2) == 1) {
                reverse(v.begin(), v.end());
            }

            for (auto it : v) {
                ans.push_back(it);
            }
            i++;
        }
        int j = 1;
        while(j<m) {
            int l = n - 1;
            int h = j;
            vector<int> v;

            while (l >= 0 && h < m) {
                v.push_back(mat[l][h]);
                l--;
                h++;
            }

            if (((n - 1 + j) % 2) == 1) {
                reverse(v.begin(), v.end());
            }

            for (auto it : v) {
                ans.push_back(it);
            }
            j++;
        }

        return ans;
    }
};
