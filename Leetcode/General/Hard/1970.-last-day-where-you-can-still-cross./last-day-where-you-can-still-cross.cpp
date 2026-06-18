class Solution {
public:
    int r;
    int c;
    vector<vector<int>> directions{{-1,0},{1,0},{0,1},{0,-1}};

    bool BFS(vector<vector<int>>& grid,int i,int j){
        queue<pair<int,int>> que;
        que.push({i,j});
        grid[i][j] = 1; //visited

        while(!que.empty()){
            auto temp = que.front();
            que.pop();

            int x = temp.first;
            int y = temp.second;

            if(x == r-1) return true;

            for(auto & dir:  directions){
               int nx = x + dir[0];
               int ny = y + dir[1];
               
               if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 0){
                que.push({nx,ny});
                grid[nx][ny] = 1;
               }
            } 
        }

        return false;
        
    }
    bool canCross(vector<vector<int>>& cells,int mid){
        vector<vector<int>> grid(r,vector<int>(c));

        for(int i = 0;i<= mid;i++){
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
            grid[x][y] = 1; //land --> water 
        }

        for(int j = 0;j<c;j++){
            if(grid[0][j] == 0 && BFS(grid,0,j)){
                return true;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        r = row;
        c = col;
        int days = cells.size();

        int l = 0;
        int r = days-1;
        int lastday =0;
        

        while(l <= r){
            int mid = l + (r - l)/2;
            if(canCross(cells,mid)){
                lastday = mid+1;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return lastday;
    }
};