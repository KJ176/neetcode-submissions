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
        unordered_set<int> uniques;
        uniques.insert(n);
        while(n != 1) {
            n = sumOfSquares(n);
            if (uniques.count(n)) return false;
            uniques.insert(n);
        }
        return true;
    }
};
