class Solution {
public:
    vector<string>ans;
    bool isvalid(string s){
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(!st.empty() && s[i]==')'){
                st.pop();
            }
            else{
                return false;
            }
        }
        if(st.empty())return true;
        return false;
    }
    void solve(string s, int i, int n) {
    if (i == 2 * n) {
        if (isvalid(s))
            ans.push_back(s);
        return;
    }

    s.push_back('(');
    solve(s, i + 1, n);
    s.pop_back();

    s.push_back(')');
    solve(s, i + 1, n);
    
}
    vector<string> generateParenthesis(int n) {
        
        solve("",0,n);
        return ans;
        
    }
};