class TicTacToe {
public:
    vector<vector<int>> grid;
    int n;
    TicTacToe(int n_) {
        n = n_;
        grid = vector<vector<int>> (n, vector<int> (n, 0));
    }
    
    int move(int r, int c, int player) {
        grid[r][c] = player;
        // check row
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (grid[r][j] != player) 
            {
                found = true;
                break;
            }
        }
        if (!found) return player;
        // check col
        found = false;
        for (int j = 0; j < n; j++)
        {
            if (grid[j][c] != player) 
            {
                found = true;
                break;
            }
        }
        if (!found) return player;


        // check diags
        found = false;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][i] != player) 
            {
                found = true;
                break;
            }
        }
        if (!found) return player;

        found = false;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][n-1-i] != player) 
            {
                found = true;
                break;
            }
        }
        if (!found) return player;

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
