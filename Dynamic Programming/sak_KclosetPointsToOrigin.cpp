class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        
        priority_queue<pair<int, pair<int, int>>> heap;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y;  
            heap.push({dist, {x, y}});

            
            if (heap.size() > k) {
                heap.pop();
            }
        }

       
        while (!heap.empty()) {
            pair<int, int> point = heap.top().second;
            ans.push_back({point.first, point.second});
            heap.pop();
        }

        return ans;
    }
};
