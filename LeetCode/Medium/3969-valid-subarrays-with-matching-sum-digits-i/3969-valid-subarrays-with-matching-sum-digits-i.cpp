class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            vector<int>v;
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                long long temp=sum;
                while(temp>0){
                    v.push_back(temp%10);
                    temp=temp/10;
                }
                if(v[0]==x && v.back()==x){
                    count++;
                }
                v.clear();

            }
        }
        return count;
        
    }
};