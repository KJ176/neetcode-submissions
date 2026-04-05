class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // We want shorter array first for faster binary search
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;
        bool isEvenCount = (n % 2 == 0);

        //Indicates no of elements in left side of final array serperation
        // Keeping it left side heavy in case of odd so that we know median will lie in left itself
        int left = (n1 + n2 + 1) / 2; 

        int l = 0, r = n1;
        while(l <= r) {
            int mid1 = l + ( r - l ) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            if(mid2 < n2) r2 = nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                if (isEvenCount) {
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
                } else {
                    return (double)(max(l1, l2));
                }
            } else if (l1 > r2) {
                r = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        }
        return 0;
    }
};
