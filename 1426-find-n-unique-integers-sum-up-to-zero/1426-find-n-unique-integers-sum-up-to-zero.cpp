class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int> result;

        for(int i = 0;i < n/2; i++){
            int num = i+1;
            result.push_back(num);
            result.push_back(-num);
        }

        if(n % 2 != 0) result.push_back(0);

        return result;
    }
};