if __name__ == '__main__':
    N = int(input())
    mylist = []
    var1 = 0
    var2 = 0
    for i in range(N):
        c = str(input())
        if(c[0] == 'i'):
            var1 = int(c[7])
            if(len(c) <=10):
                var2 = int(c[9])
            else:
                var2 = (int(c[9]))*10 + int(c[10])
            mylist.insert(var1,var2)
        elif(c[0] =='p' and c[1]=='r'):
            print(mylist)
        elif(c[0]=='p' and c[1]=='o'):
            mylist.pop(len(mylist)-1)
        elif(c[0]=='r' and c[2] =='m'):
            if(len(c)<=8):
                var1 = int(c[7])
            else:
                var1 = (int(c[7]))*10 + int(c[18])
            mylist.remove(var1)
        elif(c[0]=='r' and c[2] =='v'):
            mylist.reverse()
        elif(c[0] =='a'):
            if(len(c) <=8):
                var1 = int(c[7])
            else:
                var1 = (int(c[7]))*10 + int(c[8])
            mylist.append(var1)
        elif(c[0]=='s'):
            mylist.sort()
