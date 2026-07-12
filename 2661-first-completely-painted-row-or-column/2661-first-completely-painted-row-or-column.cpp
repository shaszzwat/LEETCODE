class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        unordered_map<int, pair<int, int>> mpp;
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mpp[mat[i][j]] = {i, j};
            }
        }

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for (int i = 0; i < arr.size(); i++) {
            auto it = mpp[arr[i]];
            int rown = it.first;
            int coln = it.second;

            row[rown]++;
            col[coln]++;

            if (row[rown] == m) {
                return i;
            }

            if (col[coln] == n) {
                return i;
            }
        }

        return -1;
    }
};