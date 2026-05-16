class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b ){
        return a[1] <b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt=1;
        int prev=0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=1;i<n;i++){
            if(intervals[i][0] >= intervals[prev][1]){
                cnt++;
                prev = i;
            }
        }
        return n-cnt;
    }
};
