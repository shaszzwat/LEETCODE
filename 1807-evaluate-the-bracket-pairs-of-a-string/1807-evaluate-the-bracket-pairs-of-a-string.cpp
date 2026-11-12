class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        for(int i=0;i<knowledge.size();i++){
            mpp[knowledge[i][0]]=knowledge[i][1];
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                int start=i+1;
                int end=i+1;
                for(int j=end;j<s.size();j++){
                    if(s[j]==')'){
                        end=j-1;
                        i=j;
                        break;
                    }
                }
                if(mpp.find(s.substr(start,end-start+1))==mpp.end()){
                    ans+='?';
                    continue;
                }
                string puh=mpp[s.substr(start,end-start+1)];
                ans+=puh;

            }
          
            else{
                ans+=s[i];
            }
        }
        return ans;
    
        
    }
};