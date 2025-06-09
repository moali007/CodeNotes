class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftCnt = 0;

        while(left != right){
            //longest common prefix
            left = (left >> 1);
            right = (right >> 1);
            shiftCnt++;
        }

        return (left << shiftCnt);
    }
};