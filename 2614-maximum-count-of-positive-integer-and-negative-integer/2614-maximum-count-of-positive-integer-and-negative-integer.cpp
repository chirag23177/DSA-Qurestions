class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        for(int it : nums){
            if (it >0) pos++;
            else if (it < 0) neg++;
        }
        if(pos>neg) return pos;
        else
            return neg;
    }
};