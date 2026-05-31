class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();

        sort(asteroids.begin(), asteroids.end());

        for(int i = 0; i < n; i++){
            if(asteroids[i] > mass){
                return false;
            }else{
                // mass += asteroids[i];
                if(mass + asteroids[i] > 1e5){
                    mass = 1e5;
                }else{
                    mass += asteroids[i];
                }
            }
        }

        return true;
    }
};