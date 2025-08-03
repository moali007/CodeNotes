class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos, amount;
        for (auto& f : fruits) {
            pos.push_back(f[0]);
            amount.push_back(f[1]);
        }

        // prefix sum of amounts
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + amount[i];

        int res = 0;

        // Move left first, then right
        for (int x = 0; x <= k; x++) {
            int left = startPos - x;
            int remain = k - 2 * x;
            if (remain < 0) break;
            int right = startPos + remain;
            int l = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), right) - pos.begin();
            res = max(res, pre[r] - pre[l]);
        }

        // Move right first, then left
        for (int x = 0; x <= k; x++) {
            int right = startPos + x;
            int remain = k - 2 * x;
            if (remain < 0) break;
            int left = startPos - remain;
            int l = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            int r = upper_bound(pos.begin(), pos.end(), right) - pos.begin();
            res = max(res, pre[r] - pre[l]);
        }

        return res;
    }
};
