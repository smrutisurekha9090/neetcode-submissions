class Solution {
   public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> ans(n + m, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + ans[i + j + 1];
                ans[i + j + 1] = sum % 10;
                ans[i + j] += sum / 10;
            }
        }
        string res="";
        for (int x : ans) {
            if (res.empty() && x == 0) {
                continue;
            }
            res += char(x + '0');
        }
        if(res.empty()) return "0";
        return res;
    }
};
