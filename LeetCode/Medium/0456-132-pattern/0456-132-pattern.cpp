class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int num1=INT_MIN;
        int num3=INT_MIN;
        int num2=INT_MIN;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                num2=nums[i];
                st.push(nums[i]);
                continue;
            }

            

            while(!st.empty() && nums[i]>st.top()){
                int a=st.top();
                num2=nums[i];
                num3=a;
                st.pop();
                
            }

            if(nums[i]<num3 && num3!=INT_MIN){
                return true;
            }

            st.push(nums[i]);


        }
        return false;
        
    }
};