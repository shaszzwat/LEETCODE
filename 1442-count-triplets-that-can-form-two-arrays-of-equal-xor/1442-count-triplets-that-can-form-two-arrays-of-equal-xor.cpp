class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {

            int curr = 0;

            for(int j = i; j < n; j++) {

                curr ^= arr[j];

                if(curr == 0) {
                    count += j - i;
                }
            }
        }

        return count;
    }
};