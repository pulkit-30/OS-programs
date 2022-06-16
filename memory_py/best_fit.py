n = int(input("enter no. of blocks"))
m = []
print("enter m blocks storage")
m = list(map(int, input().split()))
np = int(input("___enter number of processes___"))
print("_________enter process storage______")
process = []
process = list(map(int, input().split()))
obs = [-1]*n
ps = [-1]*n
frag = [0]*n
for i in range(0, np):
    d = 10000000
    a = -1
    for j in range(0, n):
        if(obs[j] == -1 and m[j] >= process[i]):
            x = m[j]-process[i]
            if(x < d):
                d = x
                a = j
    if(a != -1):
        ps[a] = i
        obs[a] = 0
        frag[a] = m[a]-process[i]
for i in range(0, n):
    if(ps[i] != -1):
        print("the block", i, "contains process p: ", ps[i])
for i in range(0, n):
    print("status of block", i, "is", obs[i])
for i in range(0, n):
    if(obs[i] != -1):
        print("FRAGMENTATION of block :", i, ": is :", frag[i])
s = sum(frag)
print("the sum of fragmentation is :", s)
print("the blocks which are empty are :")
for i in range(0, n):
    if(obs[i] == -1):
        print(i)
