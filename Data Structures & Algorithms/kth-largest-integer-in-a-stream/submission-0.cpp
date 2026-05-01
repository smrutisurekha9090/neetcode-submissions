class KthLargest {
public:
    priority_queue<int ,vector<int> ,greater<int>>minh;
    int x;
    KthLargest(int k, vector<int>& nums) {
        x=k;
        for(int i=0;i<nums.size();i++){
            minh.push(nums[i]);
            if(minh.size()>k){
                minh.pop();
            }
        }
    }
    
    int add(int val) {
       minh.push(val); 
       if(minh.size()>x){
        minh.pop();
       }
       return minh.top();
    }
};
