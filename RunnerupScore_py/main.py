if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    MaxVal = 0
    Result = 0
    arr2 = []
    for i in sorted (arr):
        arr2.append(i)
    MaxVal = arr2[len(arr2)-1]
    CheckVal = arr2[0]
    for j in arr2:
        if(j>CheckVal and j<MaxVal):
            CheckVal = j
        if(CheckVal<MaxVal):
            Result = CheckVal
    print(Result)

