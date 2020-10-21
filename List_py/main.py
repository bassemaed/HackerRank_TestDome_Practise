if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())
    mylist = []
    resultlist = []
    for i in range(x+1):
        for j in range(y+1):
            for k in range(z+1):
                mylist.append([i,j,k])
    for c in range(len(mylist)):
        if(mylist[c][0] + mylist[c][1] + mylist[c][2] != n):
            resultlist.append(mylist[c])
    print(resultlist)
