class Solution {
public:
    string customSortString(string order, string s) {
        map<int,char>priority;
        int i=0;
        for(auto it:order){
            priority[i]=it;
            i++;
        }
        
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }

        string ans="";
        for(auto it:priority){
            if(mpp.find(it.second)!=mpp.end()){
                ans.append(mpp[it.second],it.second);
                mpp.erase(it.second);
            }
        }
        for(auto it:mpp){
            ans.append(it.second,it.first);
        }
        return ans;
    }
};