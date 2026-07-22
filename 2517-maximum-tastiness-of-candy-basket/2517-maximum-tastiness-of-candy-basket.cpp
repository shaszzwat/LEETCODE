class Solution {
public:
    bool possible(int i,vector<int>& price,int k){
        int count=1;
        int candy=price[0];

        for(int j=0;j<price.size();j++){
            if(price[j]-candy>=i){
                count++;
                candy=price[j];
            }

        }
        if(count>=k){
            return true;
        }
        return false;

    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int low=0;
        int high=1000000000;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(mid,price,k)){
                ans=max(ans,mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
        
    }
};