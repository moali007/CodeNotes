class Solution {
public:
    
    bool isPossible(int diff, vector<int>& price, int k){
        int candy = 1;
        int last = price[0];

        for(int i = 1; i < price.size(); i++){
            if(price[i] - last >= diff){
                candy++;
                last = price[i];
            }
        }

        return candy >= k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();

        sort(price.begin(), price.end());
        int s = 1;
        int e = price[n-1] - price[0];
        int ans = 0;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(isPossible(mid, price, k)){
                ans = mid;
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }

        return ans;
    }
};