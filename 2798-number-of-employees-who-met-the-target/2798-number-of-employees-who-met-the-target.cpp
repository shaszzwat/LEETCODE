class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count=0;
        for(int it:hours){
            if(it>=target){
                count++;
            }
        }
        return count;
        
    }
};