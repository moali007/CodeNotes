class Solution {
public:
    int distMoney(int money, int c) {
        // Step 1: give each child $1
        money -= c;
        if (money < 0) return -1; // not enough money for minimum requirement

        // Step 2: maximize children with exactly $8
        int full8 = money / 7;   // each child needs 7 more to reach 8
        int rem = money % 7;

        // Step 3: adjust edge cases
        if (full8 > c) return c - 1;             // can't have more 8-dollar kids than total children
        if (full8 == c && rem > 0) return c - 1; // all kids got 8, but still have leftover → invalid
        if (full8 == c - 1 && rem == 3) return c - 2; // one child gets 4 → invalid case

        return full8;
    }
};
