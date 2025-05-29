class Solution {
public:
    
    int binarySearch(int spell, vector<int>& potions, long long success){
        int s = 0;
        int e = potions.size()-1;

        int idx = -1;

        while(s <= e){
            int mid = s + (e-s)/2;

            if((spell * (long long)potions[mid]) >= success){
                idx = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return (idx == -1) ? 0 : potions.size() - idx;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        vector<int> ans(n, 0);

        sort(potions.begin(), potions.end());

        for(int i=0;i<n;i++){
            int spell = spells[i];

            ans[i] = binarySearch(spell, potions, success);
        }

        return ans;
    }
};