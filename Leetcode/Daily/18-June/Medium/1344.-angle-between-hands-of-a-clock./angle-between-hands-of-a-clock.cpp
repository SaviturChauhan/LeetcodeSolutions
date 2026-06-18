class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = (hour % 12) * 30.0 + minutes * 0.5;
        double min = (minutes * 1.0 /60) * 360;
        double diff = abs(hr-min);
        if(diff > 180) diff  = 360 - diff;
        return abs(diff);
    }
};