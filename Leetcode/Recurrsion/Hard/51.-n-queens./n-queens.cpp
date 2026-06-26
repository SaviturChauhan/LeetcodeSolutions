class Solution {
public:
    vector<vector<string>> ans;
    int N;
    // checks if current row is in attack from the previous rows or not
    bool isValid(vector<string>& grid, int r, int c) {
        // upwards
        for (int i = r - 1; i >= 0; i--) {
            if (grid[i][c] == 'Q')
                return false;
        }
        // left diagonal
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q')
                return false;
        }
        // right diagonal
        for (int i = r - 1, j = c + 1; i >= 0 && j < N; i--, j++) {
            if (grid[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void solve(vector<string>& grid, int r) {
        if (r >= N) {
            ans.push_back(grid);
            return;
        }
        for (int c = 0; c < N; c++) {
            if (isValid(grid, r, c)) {
                grid[r][c] = 'Q';
                solve(grid, r + 1);
                grid[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> grid(n, string(n, '.'));
        solve(grid, 0);
        return ans;
    }
};