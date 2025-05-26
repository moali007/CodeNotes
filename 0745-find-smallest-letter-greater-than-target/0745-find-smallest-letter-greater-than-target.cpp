class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int idx = upper_bound(letters.begin(), letters.end(), target) - letters.begin();

        char ch = (idx < n) ? letters[idx] : letters[0];
        return ch;
    }
};