class Solution {
   public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        auto convert = [m](int i, int j) { return i * m + j; };
        vector<vector<int>> distances = vector<vector<int>>(m, vector<int>(n, 0));
        vector<vector<int>> visitedCount = vector<vector<int>>(m, vector<int>(n, 0));
        queue<pair<int, int>> building_locations;
        set<pair<int, int>> building_check;

        // set obstacles to inf
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    distances[i][j] = INT_MAX;
                    if (grid[i][j] == 1) {
                        building_locations.push({i, j});
                        building_check.insert({i, j});
                    }
                }
            }
        }
        int num_buildings = building_check.size();

        // run BFS on each building
        while (!building_locations.empty()) {
            auto building = building_locations.front();
            building_locations.pop();
            if (!runBFS(building.first, building.second, m, n, grid, distances, building_check, visitedCount))
                return -1;
        }

        // return lowest value in distances
        int global_min = INT_MAX;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0 && visitedCount[r][c] == num_buildings)
                    global_min = min(global_min, distances[r][c]);
            }
        }
        if (global_min == INT_MAX) return -1;
        return global_min;
    }

    bool runBFS(int i, int j, int m, int n, vector<vector<int>>& grid,
                vector<vector<int>>& distances, set<pair<int, int>> building_check, vector<vector<int>>& visitedCount) {
        // return false if bfs does not find all other buildings
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> seen(m, vector<int>(n, 0));
        q.push(pair{pair{i, j}, 0});
        while (!q.empty()) {
            pair<int, int> cell = q.front().first;
            int level = q.front().second;
            q.pop();
            seen[cell.first][cell.second] = 1;

            if (building_check.contains(cell)) {
                building_check.erase(cell);
                if (cell != pair{i, j}) continue;
            } else {
                distances[cell.first][cell.second] += level;
                visitedCount[cell.first][cell.second]++;
            }

            for (const auto& [r, c] : {pair{1, 0}, pair{0, 1}, pair{-1, 0}, pair{0, -1}}) {
                int d = cell.first + r;
                int k = cell.second + c;
                if (0 <= d && d < m && 0 <= k && k < n && seen[d][k] == 0) {
                    if (grid[d][k] != 2) q.push(pair{pair{d, k}, level + 1});
                    seen[d][k] = 1;
                }
            }
        }
        if (!building_check.empty()) return false;
        return true;
    }
};
