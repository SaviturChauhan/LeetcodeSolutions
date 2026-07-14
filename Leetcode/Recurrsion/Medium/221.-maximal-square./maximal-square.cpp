class Solution {
public:
    int m, n;
    int ans = 0;
    int f(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 )
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (matrix[i][j] == '0')
            return dp[i][j] = 0;
        int left = f(i, j-1, matrix, dp);
        int up = f(i-1, j, matrix, dp);
        int diag = f(i - 1, j - 1, matrix, dp);
        dp[i][j] = 1 + min({left, up, diag});
        ans = max(ans, dp[i][j]);
        return dp[i][j];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f(i, j, matrix, dp);
            }
        }
        return ans * ans;
    }
};