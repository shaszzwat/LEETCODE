class Solution {
public: 
    int n;
    int m;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    bool bfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        queue<pair<int,int>>q;
        q.push({i,j});
        bool result=true;
        if(grid1[i][j]!=1){
            result=false;
        }

        grid2[i][j]=-1;
        while(!q.empty()){
            
            int orgi=q.front().first;
            int orgj=q.front().second;
            q.pop();
            
            if(grid1[orgi][orgj]!=1){
                result=false;
            }
            for(int k=0;k<4;k++){
                int newi=orgi+dir[k][0];
                int newj=orgj+dir[k][1];

                if(newi>=0 && newj>=0 && newi<n && newj <m && grid2[newi][newj]==1){
                    q.push({newi,newj});
                    grid2[newi][newj]=-1;

                }
            }
        }
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count=0;
        n=grid1.size();
        m=grid1[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && bfs(i,j,grid1,grid2)){
                    count++;
                }
            }
        }
        return count;
    }
};