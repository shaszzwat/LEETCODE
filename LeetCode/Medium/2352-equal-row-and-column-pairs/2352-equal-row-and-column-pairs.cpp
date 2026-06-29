class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>>col;
        int n=grid.size();
        
        for(int i=0;i<n;i++){
            vector<int>cols;
            for(int j=0;j<n;j++){
                cols.push_back(grid[j][i]);
            }
            col.push_back(cols);
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i]==col[j]){
                    count++;
                }

            }
        }
        return count;

        
    }
};