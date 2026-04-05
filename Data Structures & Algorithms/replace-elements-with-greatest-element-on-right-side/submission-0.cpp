class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxVal = arr.back();
        for(int i = n - 2; i >= 0 ; i--) {
            int temp = arr[i];
            arr[i] = maxVal;
            maxVal = max(temp, maxVal);
        }
        arr[n-1] = -1;
        return arr;
    }
};