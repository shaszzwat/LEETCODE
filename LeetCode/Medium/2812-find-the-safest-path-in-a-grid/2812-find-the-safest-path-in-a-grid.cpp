class Solution {
public:
    int n;
    queue<pair<pair<int, int>, int>> q1;
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    bool possible(int mid, vector<vector<int>>& pre) {

        if(pre[0][0] < mid) return false;

        vector<vector<int>> visited(n, vector<int>(n, -1));

        queue<pair<int,int>> q2;
        q2.push({0,0});
        visited[0][0] = 1;

        while(!q2.empty()){

            int i = q2.front().first;
            int j = q2.front().second;
            q2.pop();

            if(i==n-1 && j==n-1)
                return true;

            for(int k=0;k<4;k++){

                int newi=i+dir[k][0];
                int newj=j+dir[k][1];

                if(newi>=0 && newi<n && newj>=0 && newj<n){

                    if(visited[newi][newj]==-1 && pre[newi][newj]>=mid){

                        visited[newi][newj]=1;
                        q2.push({newi,newj});
                    }
                }
            }
        }

        return false;
    }

    void premat(vector<vector<int>>& pre, vector<vector<int>>& visited){

        while(!q1.empty()){

            int i=q1.front().first.first;
            int j=q1.front().first.second;
            int dist=q1.front().second;
            q1.pop();

            for(int k=0;k<4;k++){

                int newi=i+dir[k][0];
                int newj=j+dir[k][1];

                if(newi>=0 && newi<n && newj>=0 && newj<n){

                    if(visited[newi][newj]==-1){

                        visited[newi][newj]=1;
                        pre[newi][newj]=dist+1;
                        q1.push({{newi,newj},dist+1});
                    }
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        n = grid.size();

        vector<vector<int>> pre(n, vector<int>(n,0));
        vector<vector<int>> visited(n, vector<int>(n,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1){

                    q1.push({{i,j},0});
                    visited[i][j]=1;
                    pre[i][j]=0;
                }
            }
        }

        premat(pre,visited);

        int low=0;
        int high=400;
        int ans=0;

        while(low<=high){

            int mid=(low+high)/2;

            if(possible(mid,pre)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans;
    }
};