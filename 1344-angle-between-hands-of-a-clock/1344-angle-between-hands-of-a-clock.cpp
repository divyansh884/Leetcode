class Solution {
public:
    double angleClock(int hour, int minutes) {
        double agmin=(minutes*6.0);
        double aghr;
        if(hour==12)
        aghr=0;
        else
        aghr=hour*30;
        aghr+=(minutes*0.5);
        double ans=abs(agmin-aghr);
        return min(ans,360-ans);
    }
};