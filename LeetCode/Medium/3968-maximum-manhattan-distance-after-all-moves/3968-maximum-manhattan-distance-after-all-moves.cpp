class Solution {
public:
    int maxDistance(string moves) {
        vector<int>v(2,0);
        int count=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L'){
                v[0]--;
            }
            else if(moves[i]=='R'){
                v[0]++;
            }
            else if(moves[i]=='U'){
                v[1]++;
            }
            else if(moves[i]=='D'){
                v[1]--;
            }
            else{
                count++;
            }

        }
        int dist= abs(v[0])+abs(v[1])+count;
        return dist;
        
    }
};