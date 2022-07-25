import math
import string
stack = []
postStr = ""
precedence = list("+-*/^$")

def getPrecedence(op):
    return math.ceil(precedence.index(op)/2)



exp = "(" + input("Expression: ").lower() + ")"

for char in exp:
    if char == "(":
        stack.append(char)
    elif (char in string.ascii_lowercase + string.digits):
        postStr += char
    elif char == ")":
        while stack[-1] != "(":
            postStr += stack[-1]
            stack.pop()
        stack.pop()
    elif char in precedence:
        while stack[-1] != "(" and getPrecedence(char) <= getPrecedence(stack[-1]):
            # if char == "$" or char=="^":
            #     break
            # else:
            postStr += stack[-1]
            stack.pop()
        
        stack.append(char)


print(postStr)
    