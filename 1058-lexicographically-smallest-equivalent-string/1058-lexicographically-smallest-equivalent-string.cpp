class Solution {
public:
    
    char dfs(char curr_ch, unordered_map<char, vector<char>> &adj, vector<int> &vis){
        vis[curr_ch - 'a'] = 1;

        char minChar = curr_ch;

        for(char ch : adj[curr_ch]){
            if(vis[ch - 'a'] == 0){

                minChar = min(minChar, dfs(ch, adj, vis));
            }
        }

        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();

        //create graph
        unordered_map<char, vector<char>> adj;
        for(int i=0;i<n;i++){
            char u = s1[i];
            char v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result;

        for(int i=0;i<m;i++){
            //baseStr ke harr char ke lie naya dfs chalega
            char ch = baseStr[i];
            
            vector<int> vis(26, 0);

            char minChar = dfs(ch, adj, vis);

            result.push_back(minChar);
        }

        return result;
    }
};