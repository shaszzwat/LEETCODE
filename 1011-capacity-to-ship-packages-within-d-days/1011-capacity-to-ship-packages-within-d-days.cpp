class Solution {
public:
    bool possible(long long val,int days,vector<int>& weights){
        int curr=0;
        int count=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>val){
                return false;
            }
            if(count+weights[i]>val){
                curr++;
                count=weights[i];
            }
            else{
                count+=weights[i];
            }



        }
        return curr+1<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long low=0;
        long long high=accumulate(weights.begin(),weights.end(),0LL);
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(possible(mid,days,weights)){
                ans=mid;
                high=mid-1;

            }
            else{
                low=mid+1;
            }
        }
        return (int)ans;
        
    }
};