class Solution {
public:
    bool bs(vector<int>v,int target){
        int low=0;
        int high=v.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(v[mid]==target){
                return true;
            }
            if(v[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(bs(matrix[i],target)){
                return true;
            }
        }
        return false;

        
    }
};