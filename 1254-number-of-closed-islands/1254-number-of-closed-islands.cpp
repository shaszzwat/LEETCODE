class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&visited){
        if(i>=grid.size()||i<0||j<0||j>=grid[0].size()){
            return;
        }
        if(grid[i][j]==1 || visited[i][j]!=-1){
            return;
        }
        if(grid[i][j]==0 && visited[i][j]==-1){
            visited[i][j]=1;
            grid[i][j]=1;
        }
        dfs(i+1,j,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i,j-1,grid,visited);

    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1){
                    if(grid[i][j]==0 && visited[i][j]==-1){
                        dfs(i,j,grid,visited);

                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && visited[i][j]==-1){
                    dfs(i,j,grid,visited);
                    count++;

                }
                
            }
        }
        return count;
        
    }
};