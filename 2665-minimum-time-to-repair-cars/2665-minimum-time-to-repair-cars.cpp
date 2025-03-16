class Solution {
public:


    bool check(vector<int>& ranks, int cars, long long mid) {
        long long total = 0;
        long long n = ranks.size();

        for (int i = n - 1; i >= 0; i--) {
            total += floor(sqrt(mid / ranks[i]));  
            if (total >=cars) {
                return true;
            }
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        
        long long high = 0;
        sort(ranks.begin(), ranks.end());
        high = 1LL*ranks[0] * (cars) * (cars);
        long long low = 0;

        while (low <high) {
            long long mid = low + (high - low) / 2;  
            if (check(ranks, cars, mid)) {  
                high = mid;
            } else {
                low = mid + 1;
            }
        }
      
        return low;
    }
};