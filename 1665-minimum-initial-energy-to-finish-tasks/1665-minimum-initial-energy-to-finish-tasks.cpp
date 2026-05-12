class Solution {
public:
    int n;

    bool isPossible(vector<vector<int>>& tasks, int mid){

        for(int i = 0; i < n; i++){
            if(tasks[i][1] > mid){
                return false;
            }else{
                mid -= tasks[i][0];
            }
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        n = tasks.size();

        auto lambda = [](auto &task1, auto &task2){
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff1 > diff2;
        };

        sort(tasks.begin(), tasks.end(), lambda);

        int s = 0;
        int e = 1e9;
        int ans = INT_MAX;
        while(s <= e){
            int mid = s + (e - s)/2;

            if(isPossible(tasks, mid)){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }

        return ans;
    }
};