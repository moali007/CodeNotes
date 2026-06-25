class Solution {
public:
    double angleClock(int hour, int minutes) {
        //hour hand angle wrt refrence at 12
        double hourAngle = (30.0 * (hour % 12)) + minutes * 0.5;

        //minute hand angle wrt refrence at 12
        double minuteAngle = minutes * 6.0;

        double diffAngle = abs(hourAngle - minuteAngle);

        return min(diffAngle, 360.0 - diffAngle);
    }
};
