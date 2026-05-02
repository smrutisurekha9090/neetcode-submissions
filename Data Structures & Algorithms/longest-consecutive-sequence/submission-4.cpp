class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
       unordered_set<int>st;
       int longest=1;
       for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
       }

       for(auto it:st){
            int x=it;
            int cnt=1;
            if(st.find(x-1)==st.end()){
                while(st.find(x+1)!=st.end()){
                    x +=1;
                    cnt +=1;
                }
                longest =max(longest,cnt);
            }
       }
       return longest;

    }
};
