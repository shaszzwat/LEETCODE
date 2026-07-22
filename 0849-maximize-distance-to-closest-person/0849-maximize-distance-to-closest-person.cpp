class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int>v(n,1e8);
        int lastfound=1e8;
        for(int i=0;i<n;i++){
            
            if(seats[i]==1){
                lastfound=i;
                continue;
            }
            if(lastfound==1e8){
                continue;
            }
            v[i]=i-lastfound;
        }

        int lastfoundb=1e8;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1){
                lastfoundb=i;
            }
            v[i]=min(v[i],lastfoundb-i);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,v[i]);
        }
        return maxi;


        
    }
};