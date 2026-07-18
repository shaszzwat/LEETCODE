class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int,int>>v;
        int n=values.size();
        for(int i=0;i<n;i++){
            v.push_back({values[i],labels[i]});
        }
        sort(v.begin(),v.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.first>b.first;
        });

        vector<int>visited(20001,0);
        int sum=0;

        for(int i=0;i<n;i++){
            if(numWanted==0){
                break;
            }
            if(visited[v[i].second]==useLimit){
                continue;
            }
            else{
                sum+=v[i].first;
                visited[v[i].second]++;
                numWanted--;
            }
        }
        return sum;
        
    }
};