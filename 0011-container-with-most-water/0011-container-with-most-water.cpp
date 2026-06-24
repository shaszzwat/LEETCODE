class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int l=0;
        int r=height.size()-1;
        while(l<=r){
            int hei=min(height[l],height[r]);
            int width=r-l;
            maxi=max(maxi,hei*width);
            if(height[l]<=height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi;
    }
};