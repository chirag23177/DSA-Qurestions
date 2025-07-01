class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        res.push_back(intervals[0]);

        for(int i =1; i<intervals.size(); i++) {
            vector<int>& last = res.back();

            if(intervals[i][0] < last[1]) {
                count++;
            } else {
                res.push_back(intervals[i]);
            }
        }

        return count;
    }
};