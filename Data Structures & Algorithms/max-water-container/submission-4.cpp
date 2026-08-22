class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int res = 0;
        while (l < r) {
            int len = r - l;
            int height = min(heights[l], heights[r]);
            int water = len * height;
            res = max(res, water);
            if (heights[l] < heights[r]) l++;
            else r--;
        }
        return res;
    }
};

//1 500 500 2