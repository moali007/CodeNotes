class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int l=0,r=0;

        while(l < n && r < m){
            if(players[l] <= trainers[r]){
                l = l + 1;
            }
            r = r + 1;
        }
        return l;
    }
};