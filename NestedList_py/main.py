if __name__ == '__main__':
    mylist = [[]]
    name_list = []
    score_list = []
    Result_list= []
    min2_value = 0
    for _ in range(int(input())):
        name = input()
        score = float(input())
        name_list.append(name)
        score_list.append(score)
    for i in range(len(name_list)):
        mylist.append([])
        mylist[i].append(name_list[i])
        mylist[i].append(score_list[i])
    min2_value =  sorted(list(set(score_list)))[1]
    for i in range(len(name_list)):
        if mylist[i][1] == min2_value:
            Result_list.append(mylist[i][0])
    Result_list = sorted(Result_list)
    for i in range(len(Result_list)):
        print(Result_list[i])
