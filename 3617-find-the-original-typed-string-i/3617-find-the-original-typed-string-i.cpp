class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();

        //remove duplicates - adjacent
        int k=1;
        for(int i = 1; i < n; i++){
            if(word[i] == word[k-1]){
                continue;
            }else{
                swap(word[i], word[k]);
                k++;
            }
        }

        return n - k + 1;
    }
};