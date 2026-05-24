class Solution {
   public:
    int solve(int i, string& s, vector<int>& dp) {
        int n = s.size();
        if (i == n) return 1;
        if (s[i] == '0') return 0;

        if (dp[i] != -1) return dp[i];
        // take 1 digit
        int one = solve(i + 1, s, dp);

        // take 2digit
        int two = 0;
        if (i + 1 < n) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26) {
                two = solve(i + 2, s, dp);
            }
        }

        return dp[i] = one + two;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(0, s, dp);
    }
};
