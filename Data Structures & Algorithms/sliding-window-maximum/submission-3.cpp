class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> q;
        int l = 0, r = 0;

        while (r < n) {
            while(!q.empty() && nums[r] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(r);

            // Checking if current left index is out of window
            if (l > q.front()) {
                q.pop_front();
            }

            // Only possible if initial cases where window size not reached
            if ((r+1) >= k) {
                res.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }
        return res;
    }
};
