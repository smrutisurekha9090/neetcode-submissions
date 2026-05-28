class CountSquares {
public:
    map<pair<int,int>, int> mp;
    vector<pair<int,int>> points;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        mp[{x,y}]++;

        points.push_back({x,y});
    }
    
    int count(vector<int> point) {
         int x = point[0];
        int y = point[1];

        int ans = 0;

        for(auto &p : points) {

            int px = p.first;
            int py = p.second;

            // diagonal condition
            if(px == x || py == y || abs(px - x) != abs(py - y)) {
                continue;
            }
            ans += mp[{x, py}] * mp[{px, y}];
        }

        return ans;
    }
};
