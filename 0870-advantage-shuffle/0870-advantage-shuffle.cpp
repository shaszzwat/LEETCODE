class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
       
        vector<int>ans;
        multiset<int>ms;
        for(auto it:nums1){
            ms.insert(it);
        }
        for(int i=0;i<nums2.size();i++){
            auto it=ms.upper_bound(nums2[i]);
            if(it==ms.end()){
                ans.push_back(*ms.begin());
                ms.erase(ms.begin());
            }
            else{
                ans.push_back(*it);
                ms.erase(it);
            }
        }
        
        return ans;
    }
};