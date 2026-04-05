class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int weight: stones) {
            maxHeap.push(weight);
        }
        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            int res = abs(stone1 - stone2);
            if (res) {
                maxHeap.push(res);
            }
        }
        if (maxHeap.size() > 0) {
            return maxHeap.top();
        }
        return 0;
    }
};
