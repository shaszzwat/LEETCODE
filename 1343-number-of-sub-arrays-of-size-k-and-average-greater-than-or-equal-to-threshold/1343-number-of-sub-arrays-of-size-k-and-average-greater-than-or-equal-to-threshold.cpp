class Solution {
public:
    
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int ans=0;
        if(sum/k>=threshold){
            ans++;
        }
        int l=0;
        int r=k;
        while(r<arr.size()){
            sum=sum-arr[l];
            sum=sum+arr[r];
            if(sum/k >=threshold){
                ans++;
            }
            l++;
            r++;

        }
        return ans;
    
        
    }
};