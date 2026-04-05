class Solution {
    int sumOfSquares(int n) {
        int output = 0;
        while (n) {
            int digit = n % 10;
            output += digit * digit;
            n /= 10;
        }
        return output;
    }
public:
    bool isHappy(int n) {
        int slow = n, fast = sumOfSquares(n);
        while(slow != fast) {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        }
        return fast == 1;
    }
};
