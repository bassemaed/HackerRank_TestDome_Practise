class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        def getMaxScore (in_s: str, char1: str, char2: str, in_score: int) -> int:
            mystack = []
            out_score = 0
            for c in in_s:
                if(char2 == c and mystack and char1 == mystack[-1]):
                    mystack.pop()
                    out_score = out_score +in_score
                else:
                    mystack.append(c)
            return out_score, "".join(mystack)
        if (y>x):
            x, y = y, x
            char1 = 'b'
            char2 = 'a'
        else:
            char1 = 'a'
            char2 = 'b'
        score1, remaining_string = getMaxScore(s, char1, char2, x)
        score2, _ = getMaxScore(remaining_string, char2, char1, y)
        return int(score1+score2)
