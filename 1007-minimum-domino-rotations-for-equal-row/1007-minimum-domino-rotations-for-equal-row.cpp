class Solution {
public:
    int check(vector<int>& tops, vector<int>& bottoms, int x) {
        int topFlip = 0;
        int bottomFlip = 0;

        for(int i = 0; i < tops.size(); i++) {
            if(tops[i] != x && bottoms[i] != x)
                return INT_MAX;

            if(tops[i] != x)
                topFlip++;

            if(bottoms[i] != x)
                bottomFlip++;
        }

        return min(topFlip, bottomFlip);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = min(
            check(tops, bottoms, tops[0]),
            check(tops, bottoms, bottoms[0])
        );

        return ans == INT_MAX ? -1 : ans;
    }
};