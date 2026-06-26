class Solution {
public:
    long long const mod=1e9+7;
    void presum(vector<long long>&pre){
        for(int i=1;i<pre.size();i++){
            pre[i]=(pre[i-1]+pre[i])%mod;
        }
    }
    int valueAfterKSeconds(int n, int k) {
        vector<long long>pre(n,1LL);
        while(k--){
            presum(pre);
        }
        return (pre[n-1])%mod;

        
    }
};