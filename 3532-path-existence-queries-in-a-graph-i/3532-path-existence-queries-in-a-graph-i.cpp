class Solution {
public:
    vector<int>rank;
    vector<int>parent;
    int findp(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=findp(parent[x]);
    }

    void Union(int x,int y){
        int parent_x=findp(x);
        int parent_y=findp(y);
        if(parent_x==parent_y){
            return;
        }
        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }
        else if(rank[parent_y]>rank[parent_x]){
            parent[parent_x]=parent_y;
        }
        else{
            parent[parent_x]=parent_y;
            rank[parent_y]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        rank.resize(n,0);
        vector<bool>ans(queries.size(),true);
        for(int i=0;i<n-1;i++){
           if(nums[i+1]-nums[i]<=maxDiff){
            Union(i+1,i);
           }
        }
        for(int i=0;i<queries.size();i++){
            int u=findp(queries[i][0]);
            int v=findp(queries[i][1]);
            if(u==v){
                continue;
            }
            else{
                ans[i]=false;
            }


        }
        return ans;


        
    }
};