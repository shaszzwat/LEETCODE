class Solution {
public:
    vector<int>ans;
    bool sus=false;

    void bfs(int i,vector<int>&visited,unordered_map<int,vector<int>>&adj){
        queue<int>q;
        q.push(i);
        visited[i]=1;

        while(!q.empty()){
            if(sus){
                break;
            }
            int a=q.front();
            ans.push_back(a);
            q.pop();
            for(auto it:adj[a]){
                if(visited[it]==-1){
                    visited[it]=1;
                    q.push(it);
                }
                if(visited[it]==-2){
                    sus=true;
                    break;
            
                    
                }
            }

        }


    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        unordered_map<int,vector<int>>adj;
        for(int i=0;i<invocations.size();i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int>visited(n,-1);

        queue<int>q;
        q.push(k);
        visited[k]=-2;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto it:adj[a]){
                if(visited[it]==-1){
                    visited[it]=-2;
                    q.push(it);
                }
            }

        }
        

        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                bfs(i,visited,adj);
            }
        }
        vector<int>ans2;
        if(sus){
            for(int i=0;i<n;i++){
                ans2.push_back(i);
            }
            return ans2;
        }
        return ans;

        
    }
};