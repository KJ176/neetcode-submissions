class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        priority_queue<int> maxHeap;
        for(int count: freq) {
            if (count > 0) {
                maxHeap.push(count);
            }
        }

        int time = 0;
        queue<pair<int, int>> q;

        while (!maxHeap.empty() or !q.empty()) {
            time++;
            if(!maxHeap.empty()) {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) q.push({ cnt, time + n });
            }
            if(!q.empty()) {
                if (time == q.front().second) {
                    maxHeap.push(q.front().first);
                    q.pop();
                }
            }
        }
        return time;
    }
};
