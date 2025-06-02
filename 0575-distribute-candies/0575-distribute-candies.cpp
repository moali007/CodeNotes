class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();

        int eat = n/2;

        unordered_set<int> st(candyType.begin(), candyType.end());

        if(st.size() > eat){
            return eat;
        }
        else 
         return st.size();
    }
};