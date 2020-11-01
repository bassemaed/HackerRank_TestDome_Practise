if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    average = 0
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    for i in range(len(scores)):
        average =  average+student_marks[query_name][i]
    average =  average/len(scores)
    formatted_average= "{:.2f}".format(average)
    print(formatted_average)
