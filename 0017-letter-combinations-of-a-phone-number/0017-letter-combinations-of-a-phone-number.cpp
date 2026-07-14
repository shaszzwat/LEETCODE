class Solution {
public:
    int n;
    void solve(int i,string &temp,unordered_map<int,string>&mpp,vector<string>&ans,string &digits){
        if(i>=n){
            ans.push_back(temp);
            return;
        }

        int ch=digits[i]-'0';
        string s=mpp[ch];
        for(auto it:s){
            temp.push_back(it);
            solve(i+1,temp,mpp,ans,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n=digits.size();
        vector<string>ans;
        unordered_map<int,string>mpp;
        mpp[2]="abc";
        mpp[3]="def";
        mpp[4]="ghi";
        mpp[5]="jkl";
        mpp[6]="mno";
        mpp[7]="pqrs";
        mpp[8]="tuv";
        mpp[9]="wxyz";

        string temp="";
        solve(0,temp,mpp,ans,digits);
        return ans;

        
    }
};