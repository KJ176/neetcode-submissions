class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;

        int l = 0;

        for (int r = 0; r < nums.size(); r++) {

            // Remove smaller elements from back
            while (!q.empty() && nums[r] > nums[q.back()]) {
                q.pop_back();
            }

            q.push_back(r);

            // Remove indices outside the window
            if (q.front() < l) {
                q.pop_front();
            }

            // Window has reached size k
            if (r >= k - 1) {
                res.push_back(nums[q.front()]);
                l++;
            }
        }

        return res;
    }
};