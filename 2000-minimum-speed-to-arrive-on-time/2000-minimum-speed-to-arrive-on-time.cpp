class Solution {
public:
    bool isPossible(int speed, vector<int>& dist, double hour) {
        double time = 0.0;
        int n = dist.size();
        
        for (int i = 0; i < n; i++) {
            double t = dist[i] * 1.0 / speed;
            if (i != n - 1) time += ceil(t);
            else time += t; // last ride exact
        }

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s = 1, e = 1e7;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPossible(mid, dist, hour)) {
                ans = mid;       // record feasible speed
                e = mid - 1;     // try smaller
            } else {
                s = mid + 1;     // need larger speed
            }
        }
        return ans;
    }
};
