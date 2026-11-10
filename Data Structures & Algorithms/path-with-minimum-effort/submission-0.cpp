class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int min_step = INT_MAX;

        vector<vector<int>> seen (m, vector<int> (n, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> q;
        q.push({0, 0, 0});
        seen[0][0] = 0;
        while (!q.empty()) {
            auto [max_step, row, col] = q.top();
            q.pop();
            if (row == m-1 && col == n-1)
            {
                return max_step;
            }

            for (const auto & [r, c] : {pair{1,0}, pair{0,1}, pair{-1,0}, pair{0,-1}}) {
                int d = row + r;
                int k = col + c;
                if (0 <= d && d < m && 0 <= k && k < n) {
                    int new_max_step = max(max_step, abs(heights[row][col] - heights[d][k]));
                    if (new_max_step < seen[d][k]) {
                        q.push({new_max_step, d, k});
                        seen[d][k] = new_max_step;
                    }
                }
            }   
        }

        return -1;
    }
};