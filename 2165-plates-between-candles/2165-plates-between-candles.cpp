class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        vector<int> plates;

        vector<int> barsIdx;
        for(int i=0;i<n;i++){
            if(s[i] == '|') barsIdx.push_back(i);
        }

        if(barsIdx.size() == 0) return {0};

        for(auto q : queries){
            int l = q[0];
            int r = q[1];
            if(l == r){
                plates.push_back(0);
                continue;
            }
            int leftbarIdx = lower_bound(barsIdx.begin(),barsIdx.end(),l) - barsIdx.begin();
            int left_bar = barsIdx[leftbarIdx];
            int rightbarIdx = upper_bound(barsIdx.begin(),barsIdx.end(),r) - barsIdx.begin() - 1; //finds first bar aequal to or less than r
            int right_bar = barsIdx[rightbarIdx];
            cout<<left_bar<<" "<<right_bar<<endl;
            //plates b/w  = (right_bar - left_bar) - 1 - bars_in_between

            if(right_bar - left_bar <= 1){
                plates.push_back(0);
            }
            else{
                //bars in between left_bar and right_bar
                int bars_in_between = rightbarIdx - leftbarIdx - 1;
                // for(int i=left_bar+1;i<right_bar;i++){
                //     if(s[i] == '|') bars_in_between++;
                // }

                plates.push_back((right_bar - left_bar) - 1 - bars_in_between);
            }
            
        }
        
        return plates;
    }
};