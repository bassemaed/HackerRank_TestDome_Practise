class Solution:
    def mySqrt(self, x: int) -> int:
        result = 0
        if(x<2):
            return x
        left, right = 1, x
        while left <= right:
            mid = int((left+right)/2)
            mid_squared = mid*mid
            if mid_squared == x:
                return mid
            elif mid_squared > x:
                right = mid-1
            else:
                left = mid+1
        return round(right)
