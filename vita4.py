from itertools import product
def sum_of_tup(n):
    sum=0
    for i in range(len(n)):
        sum=sum+int(n[i])
        
    return sum

low,high=map(int,input().split())
k=int(input())
lst=[]
for i in range(low,high+1):
    lst.append(str(i))

coun=0

per=product(lst,repeat=k)
for i in per:
    if(sum_of_tup(i)%2==0):
        coun=coun+1

print(coun%1000000007,end='')