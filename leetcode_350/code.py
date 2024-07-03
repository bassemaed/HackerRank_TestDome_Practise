class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        resultList = []
        hashMap = {}
        hashMap2 = {}
        for number in nums1:
            if number in hashMap:
                hashMap[number] += 1
            else:
                hashMap[number] = 1
        for number2 in nums2:
            if number2 in hashMap2:
                hashMap2[number2] += 1
            else:
                hashMap2[number2] = 1

        for element in hashMap:
            if element in hashMap2:
                x = min(hashMap[element],hashMap2[element])
                for _ in range(x):
                    resultList.append(element)
        return resultList
