class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        int i,j;
        i = 0;
        j = height.size() -1;

        while(i<j){
            int area = (j-i) * min(height[i], height[j]);

            maxArea = max(maxArea, area);

            if(height[i] <= height[j]) i++;
            else j--;
        }

        return maxArea;
    }
};