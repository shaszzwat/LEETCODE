
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int n = status.size();

        vector<int> haveBox(n, 0);
        vector<int> canOpen(n, 0);
        vector<int> visited(n, 0);

        queue<int> q;

      
        for (int box : initialBoxes) {
            haveBox[box] = 1;
        }

       
        for (int i = 0; i < n; i++) {
            canOpen[i] = status[i];
        }

       
        for (int box : initialBoxes) {
            if (canOpen[box]) {
                q.push(box);
                visited[box] = 1;
            }
        }

        int total = 0;

        while (!q.empty()) {

            int box = q.front();
            q.pop();

            
            total += candies[box];

            
            for (int key : keys[box]) {
                canOpen[key] = 1;

               
                if (haveBox[key] && !visited[key]) {
                    q.push(key);
                    visited[key] = 1;
                }
            }

           
            for (int newBox : containedBoxes[box]) {
                haveBox[newBox] = 1;

                
                if (canOpen[newBox] && !visited[newBox]) {
                    q.push(newBox);
                    visited[newBox] = 1;
                }
            }
        }

        return total;
    }
};
