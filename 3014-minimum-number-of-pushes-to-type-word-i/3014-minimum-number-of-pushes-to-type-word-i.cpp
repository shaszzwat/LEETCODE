class Solution {
public:
    int minimumPushes(string word) {
        vector<int>pre={0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4};
        for(int i=1;i<27;i++){
            pre[i]=pre[i]+pre[i-1];
        }
        return pre[word.size()];
        
    }
};