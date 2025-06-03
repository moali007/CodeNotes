class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();

        vector<bool> vis(n, false);
        vector<bool> vec(n, false);

        queue<pair<int, vector<int>>> q;
        set<int> st; //contains keys

        for(auto it : initialBoxes){
            q.push({it, keys[it]});
            vis[it] = true;
        }

        int count = 0;

        while(!q.empty()){
            int boxId = q.front().first;
            vector<int> keysId = q.front().second;
            q.pop();

            if(status[boxId] == 1){
                count += candies[boxId];
                vec[boxId] = true;
            }
            else if(status[boxId] == 0 && !st.empty() && st.count(boxId)){
                count += candies[boxId];
                vec[boxId] = true;
            }

            for(auto id : keysId){
                if(id == boxId) continue;
                st.insert(id);
            }

            for(auto it : containedBoxes[boxId]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push({it, keys[it]});
                }
            }
        }

        for(auto key : st){
            if(vis[key] == true && vec[key] == false) count += candies[key];
        }

        return count;
    }
};