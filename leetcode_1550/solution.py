class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        counter = 0
        returnVal = False
        for item in arr:
            if (item % 2):
                counter = counter + 1
                if (counter == 3):
                    return True
            else:
                counter = 0
        return returnVal
