class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i =0;i<nums.size();i++){
           mp[nums[i]]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()>0){
            int ele =pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};
