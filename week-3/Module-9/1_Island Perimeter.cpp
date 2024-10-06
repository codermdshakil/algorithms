// https://leetcode.com/problems/island-perimeter/description/
class Solution {
public:
    int n, m;
    bool valid(int ci, int cj) {
        if (ci >= 0 && ci < n && cj >= 0 && cj < m) {
            return true;
        } else {
            return false;
        }
    }
    bool vis[105][105];
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int ans;
    void dfs(int si, int sj, vector<vector<int>>& grid) {

        vis[si][sj] = true;
        for (int i = 0; i < 4; i++) {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if (valid(ci, cj)) {
                if (grid[ci][cj] == 0)
                    ans++;
            } else {
                ans++;
            }

            // traverse logic
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1) {
                dfs(ci, cj, grid);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        memset(vis, false, sizeof(vis));
        ans = 0;
        n = grid.size();    // row
        m = grid[0].size(); // col

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};