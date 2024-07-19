class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
      # Function to find the intersection of two lists
      def intersect_two_lists(list_1, list_2):
            list_3 = []
            list_3 = [value for value in list_1 if value in list_2]
            return list_3
        # save the candidates which are the minimum of each row and maximum of each column
        lucky_numbers_row_candidates= []
        lucky_numbers_column_candidates = []
        intersection_list = []
        # find the minimum of each row
        for i in range(len(matrix)):
            candidate = min(matrix[i])
            lucky_numbers_row_candidates.append(candidate)
        # find the maximum of each column
        for i2 in range(len(matrix[0])):
            currentMax = 0
            for i3 in range(len(matrix)):
                if matrix[i3][i2]>currentMax:
                    currentMax = matrix[i3][i2]
            lucky_numbers_column_candidates.append(currentMax)
        intersection_list = intersect_two_lists(lucky_numbers_row_candidates, lucky_numbers_column_candidates)
        return intersection_list

# A solution that uses less space
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        intersection_list = []
        # A lucky number has to be the maximum of all minimum of all rows AND the minimum of all maximum of all columns
        max_min_rows = 0
        min_max_columns = 100000
        column_len = len(matrix[0])
        row_len = len(matrix)
        for i in range(row_len):
            max_min_rows = max(min(matrix[i]), max_min_rows)
        for i2 in range(column_len):
            currentMax = max([matrix[index_row][i2] for index_row in range(row_len)])
            min_max_columns = min(currentMax, min_max_columns)
        # It is a lucky number if it is both these numbers
        if(min_max_columns == max_min_rows):
            intersection_list.append(min_max_columns)
        return intersection_list
