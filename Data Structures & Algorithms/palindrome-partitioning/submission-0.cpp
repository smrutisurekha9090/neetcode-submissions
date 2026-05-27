class Solution {
   public:
    vector<vector<string>> ans;
    bool isPalindromic(string& s) {
        int st = 0;
        int end = s.size() - 1;
        while (st < end) {
            if (s[st] != s[end]) {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    void solve(int idx, string& s, vector<string>& temp) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        string pal_s;
        for (int i = idx; i < s.size(); i++) {
            pal_s += s[i];
            if (isPalindromic(pal_s)) {
                temp.push_back(pal_s);
                solve(i + 1, s, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0, s, temp);
        return ans;
    }
};
