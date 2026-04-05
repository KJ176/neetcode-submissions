class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> arr;

        for (const string &op : operations) {
            if (op == "+") {
                int n = arr.size();
                arr.push_back(arr[n-1] + arr[n-2]);
            } 
            else if (op == "D") {
                arr.push_back(2 * arr.back());
            } 
            else if (op == "C") {
                arr.pop_back();
            } 
            else {
                arr.push_back(stoi(op));
            }
        }
        int sum = 0;
        for(int val: arr) {
            sum += val;
        }
        return sum;
    }
};