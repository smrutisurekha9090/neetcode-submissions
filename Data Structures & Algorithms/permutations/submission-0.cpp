class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& ds, vector<int>& freq) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (freq[i] == 0) {
                freq[i] = 1;
                ds.push_back(nums[i]);
                solve(nums, ds, freq);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<int> freq(nums.size(), 0);
        solve(nums, ds, freq);
        return ans;
    }
};