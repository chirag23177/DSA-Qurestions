class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long long , vector<long long> , greater<long long>>Q;

        for(int i=0; i<nums.size(); i++) {
            Q.push(nums[i]);
        }

        long long smallestVal , secondSmallestVal , minOpertions=0 , formedVal;

        while(Q.size() > 1 && Q.top() < k ) {
            minOpertions++;
            smallestVal = Q.top();
            Q.pop();
            secondSmallestVal = Q.top();
            Q.pop();
            formedVal = 2*smallestVal +  secondSmallestVal;
            Q.push(formedVal);
        } 
        return minOpertions;
    }
};