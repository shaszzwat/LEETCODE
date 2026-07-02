class Solution {
    typedef pair<int,pair<int,int>> ppi;

    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> result(m,vector<int>(n,1e8));

        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;

        pq.push({grid[0][0],{0,0}});
        result[0][0]=grid[0][0];

        while(!pq.empty()){

            int val=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();

            if(val>result[i][j]) continue;

            for(int k=0;k<4;k++){

                int newi=i+dir[k][0];
                int newj=j+dir[k][1];

                if(newi>=0 && newj>=0 && newi<m && newj<n){

                    if(result[newi][newj] > val+grid[newi][newj]){

                        result[newi][newj]=val+grid[newi][newj];
                        pq.push({result[newi][newj],{newi,newj}});
                    }
                }
            }
        }

        return result[m-1][n-1] < health;
    }
};