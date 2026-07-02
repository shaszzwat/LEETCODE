class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int j=0;
        for(int i=0;i<popped.size();i++){
            if(st.empty()){
                st.push(pushed[i]);
                continue;
            }
            while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
            st.push(pushed[i]);


        }
         while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }



        return st.empty();
        
    }
};