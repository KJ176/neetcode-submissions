class MedianFinder {
    vector<int> arr;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.emplace_back(num);
        sort(arr.begin(), arr.end());
    }
    
    double findMedian() {
        int n = arr.size();
        if (n % 2 == 0) {
            return (arr[(n/2) - 1] + arr[n/2]) / 2.0;
        } else {
            return arr[n/2] / 1.0;
        }
    }
};
