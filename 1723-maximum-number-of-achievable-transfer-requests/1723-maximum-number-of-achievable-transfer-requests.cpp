class Solution {
public:
    
    int result = INT_MIN;

    void f(int idx, int count, vector<int> &arr, vector<vector<int>>& requests){
        if(idx == requests.size()){
           bool allZero = true;
           for(auto it : arr){
              if(it != 0){
                allZero = false;
                break;
              }
           }

           if(allZero == true){
                result = max(result, count);
            }

           return;
        }

        int from = requests[idx][0];
        int to = requests[idx][1];

        //take
        arr[from] -= 1;
        arr[to] += 1;

        f(idx + 1, count + 1, arr, requests);

        //undo

        arr[from] += 1;
        arr[to] -= 1;

        //not take
        f(idx + 1, count, arr, requests);

    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        vector<int> arr(n , 0);

        f(0 , 0, arr, requests);
        
        return result;
    }
};