class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int carry = a & b;
            int sum = a ^ b;
            a = sum;
            b = carry<<1;
        }
        return a;
    }
};