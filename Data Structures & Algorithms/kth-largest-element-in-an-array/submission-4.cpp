class Solution {
private:
    int quickSelect(vector<int> &nums, int l, int r, int kth) {
        int pos = l, pivot = nums[r];
        
        for(int i = l; i < r; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[pos]);
                pos++;
            }
        }
        swap(nums[pos], nums[r]);
        if (pos == kth) return nums[pos];
        else if (pos > kth) return quickSelect(nums, l, pos - 1, kth);
        else return quickSelect(nums, pos+1, r, kth);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int kth = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, kth);
    }
};
