class Solution {
public:
    
    

    //seive of erathonos ( 1 to 1e6 )
    

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        int maxEle = *max_element(nums.begin(), nums.end());

        vector<int> isPrime(maxEle + 1, 1);
        isPrime[0] = 0;
        isPrime[1] = 0;
        for(int i = 2; i*i <= maxEle; i++){
            if(isPrime[i] == 1){
                for(int j = i*i; j <= maxEle; j += i){
                    isPrime[j] = 0;
                }
            }
        }

        unordered_map<int, vector<int>> mp; //{num, {indexes}}
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;

        int steps = 0;
        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                int idx = q.front(); q.pop();

                if(idx == n-1) return steps;

                int left = idx-1;
                int right = idx+1;

                if(left >= 0 and !vis[left]){
                    vis[left] = true;
                    q.push(left);
                }
                if(right < n and !vis[right]){
                    vis[right] = true;
                    q.push(right);
                }

                if(isPrime[nums[idx]] == 1){
                    int multiple = nums[idx];
                    while(multiple <= maxEle){
                        if(mp.count(multiple)){
                            for(auto i : mp[multiple]){
                                if(!vis[i]){
                                    vis[i] = true;
                                    q.push(i);
                                }
                            }
                            mp.erase(multiple);
                        }
                        multiple += nums[idx];
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};