class Solution {
public:
    int n;
    void solve(int index, vector<int>& cookies, vector<int> &child, int &result, int k){
        if(index == n){
            //max value of child ko unfair me daaldo
            int maxUnfair = *max_element(child.begin(), child.end());
            result = min(result, maxUnfair);

            return;
        }

        //index wali cookie - 0 se k-1 ke kisi bhi chid ko de sakte hai
        for(int i=0;i<k;i++){
            //giving index wali cookie to ith child
            child[i] += cookies[index];

            solve(index + 1, cookies, child, result, k);

            child[i] -= cookies[index];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();

        vector<int> child(k, 0);
        int result = INT_MAX;

        solve(0, cookies, child, result, k);

        return result;

    }
};