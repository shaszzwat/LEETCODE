class Solution {
public:
    void solve(string s,string ans,unordered_set<string>&st,vector<bool>&seen){
        st.insert(ans);
        for(int i=0;i<s.size();i++){
            if(seen[i]){
                continue;
            }

            seen[i]=true;
            ans.push_back(s[i]);
            solve(s,ans,st,seen);
            seen[i]=false;
            ans.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_set<string>st;
        vector<bool>seen(tiles.size(),false);
        solve(tiles,"",st,seen);
        return st.size()-1;

        
    }
};