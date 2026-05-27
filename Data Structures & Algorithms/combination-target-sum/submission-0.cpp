class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx,vector<int>& nums, int target,vector<int>temp){
            if(idx == nums.size()) return ;
            if(target == 0){
                ans.push_back(temp);
                return;
            }
            if(target < 0 ) return ;
            solve(idx+1,nums,target,temp);
            temp.push_back(nums[idx]);
            solve(idx,nums,target-nums[idx],temp);
            temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        solve(0,nums,target,temp);
        return ans;
    }
};
