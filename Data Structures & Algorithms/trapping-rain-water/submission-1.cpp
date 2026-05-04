class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>L(n) ,R(n);

        L[0]=height[0];
        R[n-1]=height[n-1];

        for(int i=1;i<height.size();i++){
            L[i]=max(height[i],L[i-1]);
        }

        for(int i=n-2;i>=0;i--){
            R[i]=max(height[i],R[i+1]);
        }

        int sum=0;
        for(int i=1;i<n-1;i++){
            sum += min(L[i],R[i]) - height[i];
        }
        return sum;
    }
};
