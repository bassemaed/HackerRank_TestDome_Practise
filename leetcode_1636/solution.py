class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
      # Bubble sort to sort the frequency in ascending order and similar frequency in descending order
        def special_bubble_sort(int_arr: list[int], int2_arr: list[int]):
            n = len(int_arr)
            for i in range(n):
                for j in range(0, n-i-1):
                    if int_arr[j]>int_arr[j+1]:
                        int_arr[j], int_arr[j+1] = int_arr[j+1], int_arr[j]
                        int2_arr[j], int2_arr[j+1] = int2_arr[j+1], int2_arr[j]
                    elif int_arr[j]==int_arr[j+1] and int2_arr[j+1]>int2_arr[j]:
                        int2_arr[j], int2_arr[j+1] = int2_arr[j+1], int2_arr[j]
                        int_arr[j], int_arr[j+1] = int_arr[j+1], int_arr[j]
            return int_arr, int2_arr
        # two lists to save the array elements and another for the frequency
        array_elements = []
        frequency_elements = []
        # loop over the numbers to fill the two lists
        for i in range(len(nums)):
            if nums[i] in array_elements:
                index = array_elements.index(nums[i])
                frequency_elements[index] = frequency_elements[index] +1
            else:
                array_elements.append(nums[i])
                frequency_elements.append(int(1))
        special_bubble_sort(frequency_elements,array_elements)
        final_result = []
        # print the result according to the sorted arrays
        for i in range(len(frequency_elements)):
            final_result.extend([array_elements[i] for x in range(frequency_elements[i])])
        return final_result
