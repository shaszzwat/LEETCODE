class Solution {
public:
    int const mod=1e9+7;
    int numSub(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ans=(ans+1)%mod;
                int j=i+1;
                while(j<s.size() && s[j]=='1'){
                    ans=(ans+j-i+1)%mod;
                    j++;
                }
                i=j-1;
            }
        }
        return ans;
        
    }
};