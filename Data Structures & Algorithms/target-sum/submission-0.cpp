class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if ((totalSum + target) % 2 != 0) return 0;
        int subsetTarget = (totalSum + target) / 2;
        if (subsetTarget < 0) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(subsetTarget + 1, 0));

        for (int i = 0; i < n + 1; i++) dp[i][0] = 1;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j < subsetTarget + 1; j++) {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][subsetTarget];
    }
};
