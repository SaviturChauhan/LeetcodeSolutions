class Solution {
public:
    int m, n;
    int ans;
    int obstacle;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void f(vector<vector<int>>& grid, int count, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1)
            return;
        if (grid[x][y] == 2) {
            if (count == obstacle)
                ans++;
            return;
        }
        grid[x][y] = -1;
        for(auto & dir : directions){
            int nx = x + dir[0];
            int ny = y + dir[1];
            f(grid,count+1,nx,ny);
        }
        grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int x = 0, y = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    obstacle++;
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        obstacle++; // starting point ko bhi count karenge
        int count = 0;
        f(grid, count, x, y);
        return ans;
    }
};