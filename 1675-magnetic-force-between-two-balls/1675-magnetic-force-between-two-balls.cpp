class Solution {
public:
    
    bool isPossible(int force, vector<int>& pos, int m){
        int prev = pos[0];
        int balls = 1;

        for(int i = 1; i < pos.size(); i++){
            int curr = pos[i];

            if(curr - prev >= force){
                balls++;
                prev = curr;
            }
        }

        return balls >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int s = 1;
        int e = position[n-1] - position[0];

        int maxForce = 0;
        
        while(s <= e){
            int mid = s + (e - s) / 2;

            if(isPossible(mid, position, m)){
                maxForce = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return maxForce;

    }
};