class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size();
        int m = nums2.size();

        int totalLeft = (n + m + 1) / 2;

        int low = 0, high = n;

        while (low <= high) {
            int px = (low + high) / 2;
            int py = totalLeft - px;

            int x1 = (px == 0) ? INT_MIN : nums1[px - 1];
            int x2 = (py == 0) ? INT_MIN : nums2[py - 1];
            int x3 = (px == n) ? INT_MAX : nums1[px];
            int x4 = (py == m) ? INT_MAX : nums2[py];

            if (x1 <= x4 && x2 <= x3) {
                if ((n + m) % 2 == 1)
                    return max(x1, x2);
                else
                    return (max(x1, x2) + min(x3, x4)) / 2.0;
            }
            else if (x1 > x4) {
                high = px - 1;
            }
            else {
                low = px + 1;
            }
        }

        return 0.0;
    }
};
