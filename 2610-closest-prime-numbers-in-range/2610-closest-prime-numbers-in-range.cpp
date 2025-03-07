using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> nums(right + 1, 1); 

        for (int i = 2; i * i <= right; i++) {  
            if (nums[i]) {
                for (int j = i * i; j <= right; j += i) {  
                    nums[j] = 0;  
                }
            }
        }

        vector<int> primes;
        for (int i = max(left, 2); i <= right; i++) {  
            if (nums[i]) {
                primes.push_back(i);
            }
        }
        if (primes.size() < 2) return {-1, -1}; 

        int minDiff = INT_MAX;
        vector<int> ans = {-1, -1};

        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                ans = {primes[i], primes[i + 1]};
            }
        }

        return ans;
    }
};