// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1;
        int e = n;

        int firstBad = n;
        while(s <= e){
            int mid = s + (e-s)/2;

            if(isBadVersion(mid)){
                firstBad = mid;
                e = mid - 1;
            }
            else if(!isBadVersion(mid)){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return firstBad;
    }
};