class Solution {
public:
    vector<pair<int,int>> directions = {
        {2, 1},
        {1, 2},
        {-1, 2},
        {-2, 1},
        {-2, -1},
        {-1, -2},
        {2, -1},
        {1, -2}
    };

    int minKnightMoves(int x, int y) {
        queue<pair<pair<int,int>, int>> q;
        set<pair<int,int>> seen;
        q.push(pair{pair{0,0}, 0});
        seen.insert(pair{0,0});

        while (!q.empty()){
            auto cell = q.front().first;
            int steps = q.front().second;
            if (cell.first == abs(x) && cell.second == abs(y)) return steps;
            q.pop();

            for (const auto & [r, c] : directions) {
                pair<int, int> new_cell = pair{cell.first + r, cell.second + c};
                if (!seen.contains(new_cell) && -2 < new_cell.first && -2 < new_cell.second) {
                    q.push(pair{new_cell, steps+1});
                    seen.insert(new_cell);
                }
            }
        }
        return -1;
    }
};
