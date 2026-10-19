class Solution {
public:
    long long minimumSteps(string s) {
        int i=0;
        long long swaps=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='0'){
                swaps+=j-i;
                i++;
            }
        }
        return swaps;
        
        
    }
};