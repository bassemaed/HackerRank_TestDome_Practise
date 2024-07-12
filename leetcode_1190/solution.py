class Solution:
    def reverseParentheses(self, s: str) -> str:
        numParentheses = 0
        stack = []
        second_stack = []
        popped_item = ' '
        for mychar in s:
            if mychar != ')':
                stack.append(mychar)
            else:
                while (len(stack) != 0):
                    popped_item = stack.pop()
                    if popped_item != '(':
                        second_stack.append(popped_item)
                    else:
                        break
                my_string = ''.join(map(str, second_stack))
                for i in second_stack:
                    stack.append(i)
                del second_stack[:]
        my_string = ''.join(map(str, stack))
        return my_string
