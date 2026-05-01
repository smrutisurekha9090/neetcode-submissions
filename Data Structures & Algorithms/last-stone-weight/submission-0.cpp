class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxpq;
        for(int i=0;i<stones.size();i++){
            maxpq.push(stones[i]);
        }
            while(maxpq.size()>=2){
                int top1=maxpq.top();
                maxpq.pop();
                int top2=maxpq.top();
                maxpq.pop();
                if(top1 !=top2){
                    maxpq.push(top1-top2);
                }
            }
      
        if(maxpq.size()>0){
            return maxpq.top();
        }
        return 0;
    }
};
