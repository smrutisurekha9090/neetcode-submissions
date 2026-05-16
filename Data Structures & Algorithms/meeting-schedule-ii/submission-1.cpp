/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(Interval &a ,Interval &b){
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),cmp); 
        priority_queue<int,vector<int> , greater<int>>pq;
        pq.push(intervals[0].end);
        for(int i=1;i<intervals.size();i++){
            int start = intervals[i].start;
            int end = intervals[i].end;
            if(start >= pq.top()){
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
    }
};
