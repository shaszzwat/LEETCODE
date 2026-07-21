class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int one=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                one++;
            }
        }
        vector<int>zero;
        int i=0;
        while(i<n){
            int cnt=0;
            if(s[i]=='0'){
                while(i<n && s[i]=='0'){
                    cnt++;
                    i++;

                }
                zero.push_back(cnt);
            }
            else{
                i++;
            }
        }
        int maxi=0;
        for(int i=1;i<zero.size();i++){
            maxi=max(maxi,zero[i]+zero[i-1]);

        }
        return maxi+one;
        
    }
};