import math
l=[]
res=0
n=int(input())
for i in range(n):
    l.append(list(map(str,input().split())))
for p in range(n):
    for q in range(n):
        if l[p][q]=='D':
            res+=1

print(math.floor(math.sqrt(res)))