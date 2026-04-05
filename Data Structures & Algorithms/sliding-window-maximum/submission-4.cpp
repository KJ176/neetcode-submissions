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

            // Remove item out of window if exists
            if (l > q.front()) {
                q.pop_front();
            }

            // Push into output -> Check if window size is reached yet though
            if (r >= k - 1) {
                res.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }
        return res;
    }
};
