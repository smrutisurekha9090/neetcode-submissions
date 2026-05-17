class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;
        for (int i = 0; i < hand.size(); i++) {
            mp[hand[i]]++;
        }
        for (auto it : mp) {
            pq.push(it.first);
        }

        while (!pq.empty()) {
            int val = pq.top();
            for (int i = val; i < val + groupSize; i++) {
                if (mp[i] == 0)
                    return false;
                else
                    mp[i]--;

                while (!pq.empty() && mp[pq.top()] == 0) {
                    pq.pop();
                }
            }
        }
        return true;
    }
};
