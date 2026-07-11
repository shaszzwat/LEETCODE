class Solution {
public:
    void dfs(int node,vector<bool>&visited,unordered_map<int,vector<int>>&mpp,int &v,int &e){
        v++;
        visited[node]=true;
        e+=mpp[node].size();
        for(auto &it:mpp[node]){
           
            if(!visited[it]){
                 
                dfs(it,visited,mpp,v,e);
            }


        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<edges.size();i++){
            mpp[edges[i][0]].push_back(edges[i][1]);
             mpp[edges[i][1]].push_back(edges[i][0]);
        }
        int res=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                int v=0;
                int e=0;
                dfs(i,visited,mpp,v,e);

                if((v*(v-1))==e){
                    res++;
                }
            }
        }
        return res;
        
    }
};