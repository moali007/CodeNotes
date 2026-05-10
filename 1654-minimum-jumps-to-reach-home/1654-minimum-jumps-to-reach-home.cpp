class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {

        unordered_set<int> forbiddenSet(forbidden.begin(), forbidden.end());

        queue<pair<int,bool>> q;

        q.push({0, false});

        set<pair<int,bool>> vis;
        vis.insert({0, false});

        int steps = 0;

        while(!q.empty()){

            int size = q.size();

            for(int i = 0; i < size; i++){

                auto [curr, lastBack] = q.front();
                q.pop();

                if(curr == x){
                    return steps;
                }

                int forward = curr + a;

                if(forward <= 6000 &&
                   !forbiddenSet.count(forward) &&
                   !vis.count({forward, false})){

                    vis.insert({forward, false});

                    q.push({forward, false});
                }

                int backward = curr - b;

                if(!lastBack &&
                   backward >= 0 &&
                   !forbiddenSet.count(backward) &&
                   !vis.count({backward, true})){

                    vis.insert({backward, true});

                    q.push({backward, true});
                }
            }

            steps++;
        }

        return -1;
    }
};