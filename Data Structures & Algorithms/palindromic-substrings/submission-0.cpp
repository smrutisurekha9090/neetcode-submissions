class Solution {
   public:
    int expand(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // odd
            ans += expand(s, i, i);
            // even
            ans += expand(s, i, i + 1);
        }
        return ans;
    }
};
