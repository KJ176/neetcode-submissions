class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        def calculator(x, y, operator):
            match operator:
                case "+": return x+y
                case "-": return x-y
                case "*": return x*y
                case "/": return int(x/y)
        
        operators = {"+", "-", "*", "/"}
        for token in tokens:
            if token in operators:
                b = stack.pop()
                a = stack.pop()
                res = calculator(a, b, token)
                stack.append(res)
            else:
                stack.append(int(token))
        return stack.pop()


