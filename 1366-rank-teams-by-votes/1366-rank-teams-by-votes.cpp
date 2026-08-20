class Solution {
public:
    string rankTeams(vector<string>& votes) {
        
        map<char, vector<int>> mpp;
        int n = votes[0].size();

        for(char c : votes[0])
            mpp[c] = vector<int>(n, 0);

        for(int i = 0; i < votes.size(); i++){
            for(int j = 0; j < n; j++){
                mpp[votes[i][j]][j]++;
            }
        }

        vector<char> v;

        for(auto it : mpp)
            v.push_back(it.first);

        sort(v.begin(), v.end(), [&](char a, char b) {
            
            for(int i = 0; i < n; i++){
                if(mpp[a][i] != mpp[b][i])
                    return mpp[a][i] > mpp[b][i];
            }

            return a < b;
        });

        string ans = "";

        for(char c : v)
            ans += c;

        return ans;
    }
};