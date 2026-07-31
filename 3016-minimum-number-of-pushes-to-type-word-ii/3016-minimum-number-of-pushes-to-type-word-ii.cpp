class Solution {
public:
    int minimumPushes(string word) {
        int one=8;
        int two=8;
        int three=8;
        
        unordered_map<char,int>mpp;
        for(auto it:word){
          mpp[it]++;
        }
        vector<pair<char,int>>v;
        for(auto it:mpp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[](pair<char,int>&a,pair<char,int>&b){
            return a.second>b.second;
        });
        mpp.clear();

        for(int i=0;i<v.size();i++){
            
            if(one>0){
                mpp[v[i].first]=1;
                one--;
            }
             else if(two>0){
                mpp[v[i].first]=2;
                two--;
            }
             else if(three>0){
                mpp[v[i].first]=3;
                three--;
            }
            else{
                mpp[v[i].first]=4;
            }

        }


       
        int count=0;
        for(auto it:word){
            count+=mpp[it];
        }
        return count;
        
    }
};