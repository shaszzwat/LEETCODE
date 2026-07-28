class Solution {
public:
    bool check1(vector<int>& temp){
        return temp[2]==0 && temp[3]==0 && temp[4]==0 && temp[5]==0;
    }

    bool check2(vector<int>& temp){
        return temp[4]==0 && temp[5]==0 && temp[6]==0 && temp[7]==0;
    }

    bool check3(vector<int>& temp){
        return temp[6]==0 && temp[7]==0 && temp[8]==0 && temp[9]==0;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int n1 = reservedSeats.size();
        sort(reservedSeats.begin(), reservedSeats.end());

        vector<int> seat(11, 0);
        vector<int> temp(11, 0);

        int ans = 0;
        int rows = 0;

        for(int i = 0; i < n1; i++){
            rows++;
            int curr = reservedSeats[i][0];
            int j = i;

            while(j < n1 && reservedSeats[j][0] == curr){
                temp[reservedSeats[j][1]] = 1;
                j++;
            }

            if(check1(temp) && check3(temp)){
                ans += 2;
            }
            else if(check1(temp) || check2(temp) || check3(temp)){
                ans++;
            }

            i = j - 1;
            temp = seat;
        }

        ans += (n - rows) * 2;

        return ans;
    }
};