class Solution {
public:
    bool valid(vector<int>v){
        unordered_map<int,int>mpp;
        for(auto it:v){
            mpp[it]++;
        }
        return (mpp.size()==1);
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        vector<int>one=nums;
        vector<int>minus=nums;
        int kk=k;
        for(int i=0;i<nums.size()-1;i++){
            if(one[i]==1){
                continue;
            }
            else{
                if(k>0){
                    k--;
                    one[i]=-one[i];
                    one[i+1]=-one[i+1];
                }
            }
        }

        for(int i=0;i<nums.size()-1;i++){
            if(minus[i]==-1){
                continue;
            }
            else{
                if(kk>0){
                    kk--;
                    minus[i]=-minus[i];
                    minus[i+1]=-minus[i+1];
                }
            }
        }

        if(valid(nums) || valid(one) || valid(minus)){
            return true;
        }
        return false;
        
    }
};