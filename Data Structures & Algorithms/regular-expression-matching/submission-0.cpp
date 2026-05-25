class Solution {
   public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        // both empty
        if (i == 0 && j == 0) return true;

        // pattern empty
        if (j == 0) return false;

        // string empty
        if (i == 0) {
            // pattern must be like a*b*c*
            for (int k = 1; k <= j; k += 2) {
                if (k == j || p[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        // exact match or .
        if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }

        // *
        if (p[j - 1] == '*') {
            // ignore x*
            bool notTake = solve(i, j - 2, s, p, dp);
            bool take = false;

            // match previous char
            if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                take = solve(i - 1, j, s, p, dp);
            }
            return dp[i][j] = take || notTake;
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(n, m, s, p, dp);
    }
};