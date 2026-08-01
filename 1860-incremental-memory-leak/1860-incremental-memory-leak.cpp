class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int curr=1;
        int maxi=0;
        if(memory1>=memory2){
            maxi=memory1;
        }
        else{
            maxi=memory2;
        }
        int count=0;
        while(maxi>=curr){
            count++;
            if(maxi==memory1){
                
                memory1-=curr;
            }
            else{
                
                memory2-=curr;
            }
            curr++;
            maxi=max(memory1,memory2);
        }
        return{count+1,memory1,memory2};
        
    }
};