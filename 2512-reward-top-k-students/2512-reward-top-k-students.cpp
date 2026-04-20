class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback,
                           vector<string>& negative_feedback,
                           vector<string>& report,
                           vector<int>& student_id,
                           int k) {

        unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> neg(negative_feedback.begin(), negative_feedback.end());

        int n = report.size();
        vector<pair<int,int>> score; // {points, id}

        for(int i = 0; i < n; i++){
            stringstream ss(report[i]);
            string word;
            int points = 0;

            while(ss >> word){
                if(pos.count(word)) points += 3;
                else if(neg.count(word)) points -= 1;
            }

            score.push_back({points, student_id[i]});
        }

        // sort: high score first, then small id
        sort(score.begin(), score.end(), [](auto &a, auto &b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(score[i].second);
        }

        return ans;
    }
};