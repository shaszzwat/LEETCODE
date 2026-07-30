class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {

        stack<int>st;
        int count=0;
        for(int i=0;i<nums.size();i++){
            bool flag=false;
            int j=i;
            if(st.empty()){
                st.push(nums[i]);
                continue;
            }
            if(nums[i]>=st.top()){
                st.push(nums[i]);
                continue;
            }
            while(j<nums.size() && nums[j]<st.top()){
                j++;
                flag=true;

            }
            if(flag){
                count++;
                st.pop();
            }
            i=j-1;



        }
        return count+st.size();
        
    }
};