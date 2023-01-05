class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double ans=0.0;
        ans=1.0/(double)2;
        return n==1?1.0/n:ans;
    }
};
