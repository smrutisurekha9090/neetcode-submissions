class Solution {
   public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();

        vector<int> ans(queries.size());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        int i = 0;

        for (auto it : q) {
            int query = it.first;
            int idx = it.second;

            // add intervals
            while (i < n && intervals[i][0] <= query) {
                int l = intervals[i][0];
                int r = intervals[i][1];

                int size = r - l + 1;

                pq.push({size, r});

                i++;
            }

            // remove invalid intervals
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            // answer
            if (pq.empty()) {
                ans[idx] = -1;
            } else {
                ans[idx] = pq.top().first;
            }
        }

        return ans;
    }
};