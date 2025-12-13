class Solution {
public:
    
    bool isValid(const string& s) {
        if (s.empty()) return false;
        for (char ch : s) {
            if (isalnum(static_cast<unsigned char>(ch)) || ch == '_')
                continue;
            return false;
        }
        return true;
    }

    vector<string> validateCoupons(
        vector<string>& code,
        vector<string>& businessLine,
        vector<bool>& isActive
    ) {
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<string, string>> valid; 
        // {businessLine, code}

        int n = code.size();
        for (int i = 0; i < n; i++) {
            if (isValid(code[i]) && isActive[i] &&
                priority.count(businessLine[i])) {
                valid.push_back({businessLine[i], code[i]});
            }
        }

        sort(valid.begin(), valid.end(),
            [&](const auto& a, const auto& b) {
                if (priority[a.first] != priority[b.first])
                    return priority[a.first] < priority[b.first];
                return a.second < b.second;
            }
        );

        vector<string> result;
        for (auto& p : valid)
            result.push_back(p.second);

        return result;
    }
};
