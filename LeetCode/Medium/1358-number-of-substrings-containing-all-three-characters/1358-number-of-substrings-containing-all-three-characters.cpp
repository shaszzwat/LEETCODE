class Solution {
public:
    int solve(string &s,int k){
        unordered_map<char,int>mpp;
        int r=0;
        int l=0;
        int count=0;
        while(r<s.size()){
            mpp[s[r]]++;
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                    
                }
                l++;
            }
            count+=r-l+1;
            r++;


        }
        return count;

    }
    int numberOfSubstrings(string s) {

        return solve(s,3)-solve(s,2);
        
    }
};