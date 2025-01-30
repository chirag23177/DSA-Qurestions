class Solution {
public:
    double myPow(double x, int n) {
        return func(x, static_cast<long>(n));
    }

    double func(double x, long n){
        if(n==0)return 1;
        if(n<0)return 1/func(x,-n);
        if(n%2 == 0)return func(x*x, n/2);
        else return x*func(x*x, (n-1)/2);
    }
};