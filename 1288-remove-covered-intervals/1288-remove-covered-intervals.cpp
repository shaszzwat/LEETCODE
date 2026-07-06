class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
     vector<vector<int>>ans;
     sort(intervals.begin(),intervals.end(),[](const vector<int>a,const vector<int>b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        else{
            return a[0]<b[0];
        }
     });
     ans.push_back(intervals[0]);
     for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=ans.back()[1] && intervals[i][1]<=ans.back()[1] ){
            continue;
        }
        else{
            ans.push_back(intervals[i]);
        }

     }

     return ans.size();   
    }
};