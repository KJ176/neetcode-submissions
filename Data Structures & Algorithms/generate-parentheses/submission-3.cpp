class Solution {
public:
    void solver(string seq, int open, int close, vector<string>& res) {
        if(open == 0 && close == 0) {
            res.push_back(seq);
            return;
        } else if(open == close) {
            string newSeq = seq + '(';
            solver(newSeq, open - 1, close, res);
        } else if (open == 0) {
            string newSeq = seq + ')';
            solver(newSeq, open, close - 1, res);
        } else {
            string seq1 = seq + '(';
            solver(seq1, open - 1, close, res);
            string seq2 = seq + ')';
            solver(seq2, open, close - 1, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        string seq = "";
        vector<string> res;
        solver(seq, n, n, res);
        return res;
    }
};
