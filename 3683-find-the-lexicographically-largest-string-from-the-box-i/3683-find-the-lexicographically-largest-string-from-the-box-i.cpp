class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        if(numFriends == 1) return word;

        //3 friends hai to -> 2 friends ko ek-ek length ka substring ded
        //and largest 3rd  friend ko dedo n - (numFriends - 1)

        int longest = n - (numFriends - 1);
        priority_queue<string> pq;

        for(int i=0;i<n;i++){
            int longest_possible = min(longest, n-i);

            string sub = word.substr(i, longest_possible);
            pq.push(sub);
        }


        return pq.top();
     
    }
};