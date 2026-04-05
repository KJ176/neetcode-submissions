class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def solver(seq, open, close, res):
            if open == close == 0:
                res.append(seq)
            elif open == close:
                seq1 = seq + "("
                solver(seq1, open -1, close, res)
            elif open == 0:
                seq1 = seq + ")"
                solver(seq1, open, close - 1, res)
            else:
                seq1 = seq + "("
                seq2 = seq + ")"
                solver(seq1, open -1, close, res)
                solver(seq2, open, close - 1, res)

        res = []
        seq = ""
        solver(seq, n, n, res)

        return res