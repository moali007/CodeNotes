class Solution {
public:
    int maxBottlesDrunk(int b, int ex) {
        int ans = b;
        int empty = b;

        while(empty >= ex){
            ans += 1;
            empty = empty - ex + 1;
            ex += 1;
        }

        return ans;
    }
};