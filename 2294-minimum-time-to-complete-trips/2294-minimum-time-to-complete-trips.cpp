class Solution {
public:
    
    bool isPossible(long long mid, vector<int>& time, int totalTrips){
        long long trips = 0;

        for(int t : time){
            trips += mid / t;
        }

        return trips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();

        long long s = 1;
        long long e = (long long)*min_element(time.begin(), time.end()) * totalTrips;

        while(s < e){
            long long mid = s + (e - s) / 2;

            if(isPossible(mid, time, totalTrips)){
                e = mid;
            }else{
                s = mid + 1;
            }
        }

        return s;
    }
};