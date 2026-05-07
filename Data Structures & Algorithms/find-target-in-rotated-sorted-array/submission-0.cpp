class Solution {
public:
    int BinarySearch(vector<int>& nums, int low,int high , int target){
        int n=nums.size();
        while(low <=high){
            int mid = low+(high-low)/2;
            if(target == nums[mid]){
                return mid;
            }else if(target < nums[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
    int findMin(vector<int>& nums,  int low ,int high ,int target){
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]<nums[n-1]) return nums[0];
        low =0;
        high = n-1;
        while(low<= high){
             int mid = low + (high - low) / 2;

            int curr = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            if (nums[mid] < nums[curr] && nums[mid] < nums[prev]) {
                return mid;
            }
            if (nums[high] < nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int minIndex = findMin(nums,0,n-1,target);
        int b1 = BinarySearch(nums,0,minIndex-1,target);
        int b2 = BinarySearch(nums,minIndex,n-1,target);

        if(b1 == b2) return -1;
        if(b1 != -1) return b1;
        else return b2;
    }
};
