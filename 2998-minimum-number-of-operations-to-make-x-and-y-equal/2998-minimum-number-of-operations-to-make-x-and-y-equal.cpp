class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x==y) return 0;

        vector<int> visited(10001,-1);
        queue<pair<int,int>> q;

        q.push({x,0});
        visited[x]=1;

        while(!q.empty()) {
            int num=q.front().first;
            int val=q.front().second;
            q.pop();

            if(num==y) return val;

            int a=num-1;
            if(a>=0 && a<=10000 && visited[a]==-1) {
                visited[a]=1;
                q.push({a,val+1});
            }

            int b=num+1;
            if(b>=0 && b<=10000 && visited[b]==-1) {
                visited[b]=1;
                q.push({b,val+1});
            }

            if(num%11==0) {
                int c=num/11;
                if(visited[c]==-1) {
                    visited[c]=1;
                    q.push({c,val+1});
                }
            }

            if(num%5==0) {
                int d=num/5;
                if(visited[d]==-1) {
                    visited[d]=1;
                    q.push({d,val+1});
                }
            }
        }

        return -1;
    }
};