#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> low; // Max-heap
    priority_queue<int, vector<int>, greater<int>> high; // Min-heap

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Add to max-heap
        low.push(num);

        // Step 2: Balance by moving the largest from low to high
        high.push(low.top());
        low.pop();

        // Step 3: Maintain size property
        if (low.size() < high.size()) {
            low.push(high.top());
            high.pop();
        }
    }

    double findMedian() {
        if (low.size() > high.size()) {
            return low.top();
        } else {
            return (low.top() + high.top()) / 2.0;
        }
    }
};
