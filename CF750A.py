#!/usr/bin/python3
str = input()
n1,k1 = str.split(' ')
n = int(n1)
k = int(k1)

total = 240
c = n
for i in range(1,n+1):
    k += i*5
    if k > total:
        c = i-1
        break

print(c)