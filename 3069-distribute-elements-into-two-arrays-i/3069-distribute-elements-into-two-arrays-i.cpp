class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a;
        vector<int>b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(a.back()>b.back()){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }
        vector<int>result;
        for(auto it:a){
            result.push_back(it);
        }
        for(auto it:b){
            result.push_back(it);
        }
        return result;
        
    }
};