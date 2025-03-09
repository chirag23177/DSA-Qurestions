class Solution {
public:
    // this can be optimised further as mainting last index that fucked uo
    bool isalternating(vector<int>& colors, int start, int end) {
        
        for (int i = start + 1; i <= end; i++) {
            if (colors[i] == colors[i - 1]) {
                return false;
            }
        }
        return true;
    }
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        if (colors.size() < k) {
            return 0;
        }
        vector<int> finalcolors;
        for (int i = 0; i < colors.size(); i++) {
            finalcolors.push_back(colors[i]);
        }
        for (int i = 0; i < k - 1; i++) {
            finalcolors.push_back(colors[i]);
        }
        int lastfucked=-1;
        int last = 0;
        int finalAnswer = 0;
        if (isalternating(colors, 0, k - 1)) {
            last = 1;
            finalAnswer += 1;
        }
        // cout<<"Value of last is "<<last<<"\n";
        // cout<<"Value of finalanswer " << finalAnswer<<"\n";
        for (int i = k; i < finalcolors.size(); i++) {
            if (last == 1) {
                if (finalcolors[i] != finalcolors[i - 1]) {
                    last = 1;
                    finalAnswer += 1;
                } else {
                    lastfucked=i;
                    last = 0;
                }
            } else {
                if(i-k+1 <lastfucked)
                {
                    last=0;
                    continue;
                }
                if (isalternating(finalcolors, i - k + 1, i)) {
                    last = 1;
                    finalAnswer += 1;
                } else {
                    last = 0;
                }
            }
        }
        return finalAnswer;
    }
};