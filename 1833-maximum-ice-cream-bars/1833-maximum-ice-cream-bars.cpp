class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();

        int maxi = *max_element(costs.begin(), costs.end());

        vector<int> freq(maxi+1);

        for(int cost : costs){
            freq[cost]++;
        }

        int ans = 0;

        for(int price = 1; price <= maxi; price++){
            while(freq[price] > 0 and coins >= price){
                ans++;
                coins -= price;
                freq[price]--;
            }
        }

        return ans;
    }
};