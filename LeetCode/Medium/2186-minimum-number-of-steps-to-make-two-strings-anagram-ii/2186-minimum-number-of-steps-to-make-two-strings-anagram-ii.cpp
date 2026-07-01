class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>s1(26,0);
        
        for(auto it:s){
            s1[it-'a']++;
        }
        for(auto it:t){
            s1[it-'a']--;
        }
        int mini=0;
        for(int i=0;i<26;i++){
            mini=mini+abs(s1[i]);
        }
        return mini;

        
    }
};