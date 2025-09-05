class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // handle if k > n

        // Helper lambda to reverse a portion of the array
        auto reverse = [&](int left, int right) {
            while (left < right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        };

        // Step 1: Reverse entire array
        reverse(0, n - 1);

        // Step 2: Reverse first k elements
        reverse(0, k - 1);

        // Step 3: Reverse remaining n-k elements
        reverse(k, n - 1);
    }
};
