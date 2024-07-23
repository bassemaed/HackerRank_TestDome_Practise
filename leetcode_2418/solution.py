class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        def bubble_sort(int_arr: list[int], str_arr: list[str]):
            n = len(int_arr)
            for i in range(n):
                for j in range(0, n-i-1):
                    if int_arr[j]<int_arr[j+1]:
                        int_arr[j], int_arr[j+1] = int_arr[j+1], int_arr[j]
                        str_arr[j], str_arr[j+1] = str_arr[j+1], str_arr[j]
            return int_arr, str_arr

        heights, names =  bubble_sort(heights, names)
        return names
