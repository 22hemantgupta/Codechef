'''def result(n):
    res=(n*(n+1))//2
    return res

count1=0

for _ in range(int(input())):
    n = int(input())
    li2=[]
    lisoindex = []
    count2=0
    a = list(map(int , input().split()))
    for i in range(n):
        if a[i] % 4 == 0:
            lisoindex.append(i+1)
            li2.append(4)

        if a[i] % 4 == 2:
            lisoindex.append(i+1)
            li2.append(a[i]%4)
            count2+=1

    count = 0

    if count2 == 0:
        print(result(n))
        continue

    if(len(lisoindex) == 1):
        if(count2 == 1):
            print(result(lisoindex[0]-1)+result(n-lisoindex[0]))
            continue


    for i in range(len(lisoindex)):
        if(li2[lisoindex[i]-1] == 4):
            continue

        if i==0:
            p = lisoindex[i+1]-1
            count +=result(p)
            count-=(result(lisoindex[i]-1)+result(lisoindex[i+1]-lisoindex[i]-1))
            continue

        if i == len(lisoindex)-1:
            p = n-lisoindex[i-1]
            count += result(p)
            count -= (result(n-lisoindex[i])+result(lisoindex[i]-lisoindex[i-1]-1))
            continue

        count+=result(lisoindex[i+1]-lisoindex[i-1]-1)
        count-=(result(lisoindex[i+1]-lisoindex[i]-1)+result(lisoindex[i]-lisoindex[i-1]-1))

    print(result(n)-count)
'''
def getAnsw(n):
    res = (n*(n+1))//2
    return res

for _ in range(int(input())):
    n = int(input())
    lis2 = []
    lindex = []
    count1 = 0
    twoCount = 0
    arr = list(map(int, input().split()))
    for i in range(n):
        if arr[i] % 4 == 0:
            lindex.append(i+1)
            lis2.append(4)
        else:
            if arr[i] % 4 == 2:
                lindex.append(i + 1)
                twoCount += 1
            lis2.append(arr[i]%4)

    count = 0

    if twoCount == 0:
        print(getAnsw(n))
        continue

    if(len(lindex) == 1):
        if(twoCount == 1):
            print(getAnsw(lindex[0]-1)+getAnsw(n-lindex[0]))
            continue

    for i in range(len(lindex)):
        if lis2[lindex[i]-1] == 4:
            continue

        if i == 0:
            p = lindex[i+1]-1
            count += getAnsw(p)
            count -= (getAnsw(lindex[i]-1)+getAnsw(lindex[i+1]-lindex[i]-1))
            continue

        if i == len(lindex)-1:
            p = n-lindex[i-1]
            count += getAnsw(p)
            count -= (getAnsw(n-lindex[i])+getAnsw(lindex[i]-lindex[i-1]-1))
            continue

        count += getAnsw(lindex[i+1]-lindex[i-1]-1)
        count -= (getAnsw(lindex[i + 1] - lindex[i] - 1) + getAnsw(lindex[i] - lindex[i - 1]-1))

    print(getAnsw(n)-count)