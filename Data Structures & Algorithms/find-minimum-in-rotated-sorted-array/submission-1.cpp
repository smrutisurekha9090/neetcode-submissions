class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] <nums[n-1]) return nums[0];
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int curr = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            if (nums[mid] < nums[curr] && nums[mid] < nums[prev]) {
                return nums[mid];
            }
            if (nums[high] < nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
