class Solution {
   public:
    string encode(vector<string>& strs) {
        vector<int> v;
        string res = "";
        for (auto it : strs) {
            v.push_back(it.size());
        }
        for (auto it : v) {
            res += to_string(it) + ',';
        }
        res += '#';
        for (auto it : strs) {
            res += it;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        vector<int> v;
        int i = 0;
        while (s[i] != '#') {
            string cur = "";
            while (s[i] != ',') {
                cur += s[i];
                i++;
            }
            v.push_back(stoi(cur));
            i++;
        }
        i++;
        for (auto it : v) {
            res.push_back(s.substr(i, it));
            i += it;
        }
        return res;
    }
};
