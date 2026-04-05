class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 or x == 1) return x;
        long l = 1, r = x/2;
        long ans = 0;
        while (l <= r) {
            long mid = l + (r - l) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};