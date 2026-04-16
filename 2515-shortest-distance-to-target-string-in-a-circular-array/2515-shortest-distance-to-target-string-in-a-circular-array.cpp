class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        int mini = 1e9;
        for(int i = 0; i < n; i++){
            if(words[i] == target){
                int d1 = abs(i - startIndex);
                int d2 = n - d1;

                mini = min(mini, min(d1, d2));
            }
        }

        return mini == 1e9 ? -1 : mini;
    }
};