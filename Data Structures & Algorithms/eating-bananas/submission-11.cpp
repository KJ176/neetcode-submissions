class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = piles[0];
        for(int &pile: piles) {
            r = max(r, pile);
        }

        int res = r;

        while(l <= r) {
            int rate = l + (r - l) / 2;
            int hours = 0;
            for(int &pile: piles) {
                // hours += ceil(pile/rate);
                hours += (pile + rate - 1) / rate;
            }
            if(hours <= h) {
                res = min(res,rate);
                r = rate - 1;
            } else {
                l = rate + 1;
            }
        }
        return res;
    }
};
