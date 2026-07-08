class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>st;
        for(auto it:arr){
            st.insert(it);
        }
        unordered_map<int,int>mpp;
        int i=1;
        for(auto it:st){
            mpp[it]=i;
            i++;

        }
        vector<int>ans;
        for(auto it:arr){
            ans.push_back(mpp[it]);
        }
        return ans;
        
    }
};