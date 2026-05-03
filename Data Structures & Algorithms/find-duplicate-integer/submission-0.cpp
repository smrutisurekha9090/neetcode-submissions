class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow =nums[0];
        int first=nums[0];
        while(true){
            slow =nums[slow];
            first =nums[nums[first]];
            if(slow == first) break;
        }

        slow=nums[0];
        while(slow != first){
            slow =nums[slow];
            first = nums[first];
        }
        return slow;
    }
};
