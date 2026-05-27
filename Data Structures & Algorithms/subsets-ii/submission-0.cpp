class Solution {
   public:
    set<vector<int>> st;
    void solve(vector<int> ip, vector<int> op) {
        if (ip.size() == 0) {
            st.insert(op);
            return;
        }
        vector<int> op1 = op;
        vector<int> op2 = op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin());

        solve(ip, op1);
        solve(ip, op2);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> op;
        solve(nums, op);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
