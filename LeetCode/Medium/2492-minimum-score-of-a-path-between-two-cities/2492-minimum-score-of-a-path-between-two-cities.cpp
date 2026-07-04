class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});

        }

        vector<int>visited(n+1,-1);
        visited[1]=1;
        queue<pair<int,int>>q;
        q.push({1,1e8});
        int ans=INT_MAX;
        while(!q.empty()){
            int node=q.front().first;
            int cost=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                int nextnode=it.first;
                int cost2=it.second;
                ans=min(ans,cost2);

                
                if(visited[nextnode]==-1){
                    q.push({nextnode,min(cost,cost2)});
                    visited[nextnode]=1;
                    
                }
                

            }
            

            

        }
        return ans;
            
        

        
        
    }
};