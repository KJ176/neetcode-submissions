class MedianFinder {
public:

    priority_queue<int> maxHeap; // smaller values
    priority_queue<int, vector<int>, greater<int>> minHeap; // larger values

    MedianFinder() {

    }
    
    void addNum(int num) {
        maxHeap.push(num);
        if (!minHeap.empty() and (maxHeap.top() > minHeap.top())) {
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        } else if (minHeap.size() > maxHeap.size() + 1) {
            int val = minHeap.top();
            minHeap.pop();
            maxHeap.push(val);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else if (maxHeap.size() < minHeap.size()) {
            return minHeap.top();
        } else {
            return (double)(maxHeap.top() + minHeap.top()) / 2;
        }
    }
};
