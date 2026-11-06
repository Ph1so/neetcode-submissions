class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 1;
        int max_points = 0;
        map<pair<double, double>, set<pair<int,int>>> equations;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int x1 = points[i][0]; int x2 = points[j][0];
                int y1 = points[i][1]; int y2 = points[j][1];
                if (x1 == x2 && y1 == y2) continue;
                double m, b;
                if (x1 == x2) {
                    m = INT_MAX;
                    b = x1;
                } else {
                    m = (double)(y2 - y1) / (x2 - x1);
                    b = y1 - m * x1;
                }
                equations[{m, b}].insert({x1, y1});
                equations[{m, b}].insert({x2, y2});
                max_points = max(max_points, (int)equations[{m, b}].size());
            }
        }

        return max_points;
    }
};
