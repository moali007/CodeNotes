class Solution {
public:
    
    bool canEatAll(vector<int>& piles,int mid, int h){
        int actualHours = 0;
        for(auto &x:piles){
            actualHours += x/mid;
            if(x%mid != 0){
                actualHours++;
            }
        }
        return actualHours <= h;
    }

    //x = 7
    //mid = 3
    //actualHours+= 7/3 = 2
    //and 7%3 = 1 so actalHours++
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e= *max_element(piles.begin(),piles.end());

        while(s < e){
            int mid=s+(e-s)/2;
            //per hour can eat mid no. of bananas
            if(canEatAll(piles,mid,h)){
               e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return e;
    }
};