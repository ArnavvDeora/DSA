class Solution {
public:

    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2) {
        if (nums1[ind1] > nums2[ind2]) {
            swap(nums1[ind1], nums2[ind2]);
        }
    }

    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int len = n + m;
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                // Case 1: both pointers in nums1
                if (left < n && right < n) {
                    swapIfGreater(nums1, nums1, left, right);
                }
                // Case 2: left in nums1, right in nums2
                else if (left < n && right >= n) {
                    swapIfGreater(nums1, nums2, left, right - n);
                }
                // Case 3: both in nums2
                else {
                    swapIfGreater(nums2, nums2, left - n, right - n);
                }
                left++;
                right++;
            }

            if (gap == 1) break; // final pass done
            gap = (gap / 2) + (gap % 2);
        }

        // copy nums2 into nums1 (like Leetcode expects)
        for (int i = 0; i < m; i++) {
            nums1[n + i] = nums2[i];
        }
    }
};
