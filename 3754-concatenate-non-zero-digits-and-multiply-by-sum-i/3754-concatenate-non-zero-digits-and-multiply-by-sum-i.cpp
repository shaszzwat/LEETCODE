class Solution {
public:
    long long sumAndMultiply(int n) {

        string s=to_string(n);
        int sum=0;
        stack<char>st;
        for(auto it:s){
            if(it=='0'){
                continue;
            }
            else{
                st.push(it);
                sum+=it-'0';
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        if(ans.empty()){
            return 0;
        }
        reverse(ans.begin(),ans.end());
        long long anss=stoll(ans);
        return 1LL*anss*sum;
        
    }
};