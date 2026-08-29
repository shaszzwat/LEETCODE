class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        int count=0;
        for(int i=0;i<arr.size();i++){
            int curr=((arr[i]%k)+k)%k;
            if(curr==0){
                mpp[curr]++;
                continue;
            }
            int req=k-curr;
            if(mpp.find(req)!=mpp.end()){
                mpp[req]--;
                count++;
                if(mpp[req]==0){
                    mpp.erase(req);

                }
            }
            else{
                mpp[curr]++;
            }
        }
        if(count+(mpp[0]/2)==arr.size()/2){
            return true;
        }
        return false;
        
    }
};