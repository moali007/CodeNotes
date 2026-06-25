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

//double hourAngle = (30.0 * (hour % 12)) + minutes * 0.5;
//(30.0 * (hour % 12)) = hour wale haath ka angle wrt 12
//minutes * 0.5 = minutes ke wajha se hour wala haath thoda move hoda, vo angle
//ex: 3:30 = 30 min ke wajah se hour wala haath exact 3 par nahi hoga thoda aage hoga