class Solution {
public:
    int n;
    void solve(int index, vector<int>& cookies, vector<int> &child, vector<int> &unfair, int k){
        if(index == n){
            //max value of child ko unfair me daaldo
            int maxUnfair = *max_element(child.begin(), child.end());
            unfair.push_back(maxUnfair);

            return;
        }

        //index wali cookie - 0 se k-1 ke kisi bhi chid ko de sakte hai
        for(int i=0;i<k;i++){
            //giving index wali cookie to ith child
            child[i] += cookies[index];

            solve(index + 1, cookies, child, unfair, k);

            child[i] -= cookies[index];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();

        vector<int> child(k, 0);
        vector<int> unfair;

        solve(0, cookies, child, unfair, k);

        //minimum unfair value in unfair vector is answer
        int minUnfair = *min_element(unfair.begin(), unfair.end());

        return minUnfair;

    }
};