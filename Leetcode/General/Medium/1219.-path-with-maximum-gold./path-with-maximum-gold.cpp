class Solution {
public:
    int m,n;
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    int DFS(vector<vector<int>>& grid,int i,int j){
        if(i < 0 || i >= m || j <0 || j>= n || grid[i][j] == 0) return 0;
        int val = grid[i][j];
        grid[i][j] = 0;
        int maxg = 0;

        for(auto & dir: directions){
            int x = i + dir[0];
            int y = j + dir[1];
            maxg = max(maxg,DFS(grid,x,y));
        }
        grid[i][j] = val;
        return val+maxg;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] != 0){
                    ans = max(ans,DFS(grid,i,j));
                }
            }
        }
        return ans;
    }
};