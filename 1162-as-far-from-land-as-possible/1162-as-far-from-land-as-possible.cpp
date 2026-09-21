class Solution {
public:
    int n;

    int dir[4][2] = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    void bfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& visited) {

        queue<pair<pair<int,int>,int>> q;

        q.push({{i,j},0});

        while(!q.empty()) {

            int curi = q.front().first.first;
            int curj = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            for(int k = 0; k < 4; k++) {

                int newi = curi + dir[k][0];
                int newj = curj + dir[k][1];

                if(newi >= 0 && newj >= 0 &&
                   newi < n && newj < n) {

                    if(grid[newi][newj] == 0 &&
                       visited[newi][newj] > dist + 1) {

                        visited[newi][newj] = dist + 1;

                        q.push({{newi,newj},dist + 1});
                    }
                }
            }
        }
    }

    int maxDistance(vector<vector<int>>& grid) {

        n = grid.size();

        vector<vector<int>> visited(
            n, vector<int>(n, 1e9)
        );

        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    visited[i][j] = -1;
                }
            }
        }

        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    bfs(i, j, grid, visited);
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 0) {
                    ans = max(ans, visited[i][j]);
                }
            }
        }

        if(ans == 0 || ans == 1e9)
            return -1;

        return ans;
    }
};