class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        vector<int>minutes;
        for(int i=0;i<tp.size();i++){
            string s1=tp[i].substr(0,2);
            int x=stoi(s1);
            string s2=tp[i].substr(3,5);
            int y=stoi(s2);
            int min=x*60 + y;
            minutes.push_back(min);
        }
        sort(minutes.begin(),minutes.end());

        int mini=INT_MAX;
        for(int i=1;i<minutes.size();i++){
            mini=min(minutes[i]-minutes[i-1],mini);
        }
        int n=minutes.size();
        mini=min(mini,((minutes[0]+24*60) -minutes[n-1]));

        return mini;
        
    }
};