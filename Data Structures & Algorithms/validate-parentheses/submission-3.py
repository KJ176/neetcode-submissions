class Solution:
    def isValid(self, s: str) -> bool:
        mapper = { ")" : "(", "]" : "[", "}" : "{" }
        stack = []

        for c in s:
            if mapper.get(c):
                if stack and stack[-1] == mapper[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        return len(stack) == 0