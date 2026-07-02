class Solution {
public:
    int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    typedef pair<int,pair<int,int>>ppi;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1){
            if(grid[0][0]==1){
                return -1;
            }
            else{
                return 1;
            }
        }
        if(grid[0][0]==1){
            return -1;
        }
        vector<vector<int>>res(n,vector<int>(n,1e8));


        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        pq.push({1,{0,0}});
        res[0][0]=1;
        while(!pq.empty()){
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            int dist=pq.top().first;
            pq.pop();
            for(int k=0;k<8;k++){
                int newi=i+dir[k][0];
                int newj=j+dir[k][1];

                if(newi>=0 && newj>=0 && newi<n && newj<n){
                    if(grid[newi][newj]==0){
                        if(dist+1<res[newi][newj]){
                            res[newi][newj]=dist+1;
                            pq.push({dist+1,{newi,newj}});
                        }
                    }
                }
            }
        }
        if(res[n-1][n-1]==1e8){
            return -1;
        }
        return res[n-1][n-1];

    }
};