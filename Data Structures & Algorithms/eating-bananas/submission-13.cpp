class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = piles[0];
        for(int pile : piles) {
            r = max(r, pile);
        }

        int res = r;
        while(l <= r) {
            int rate = l + (r - l) / 2;
            long long time = 0;
            for(int pile : piles) {
                time += (pile + rate - 1LL) / rate; // (Ensure no round down due to int)
            }
            if (time <= h) {
                res = rate;
                r = rate - 1;
            } else {
                l = rate + 1;
            }

        }
        return res;
    }
};
