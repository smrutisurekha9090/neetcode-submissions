class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (auto it : t) {
            mp[it]++;
        }
        int cnt = mp.size();
        int i = 0;
        int j = 0;
        int minLen = INT_MAX;
        int start = 0;
        while (j < s.size()) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    cnt--;
                }
            }
            while (cnt == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }
                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) {
                        cnt++;
                    }
                }
                i++;
            }
            j++;
        }
        if (minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};
