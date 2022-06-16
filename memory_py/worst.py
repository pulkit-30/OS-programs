n = int(input("enter no. of blocks"))
memory = []
print("enter memory blocks storage")
memory = list(map(int, input().split()))
np = int(input("enter no. of processes"))
print("enter processes storage")
process = []
process = list(map(int, input().split()))
obs = [-1]*n
ps = [-1]*n
frag = [0]*n
for i in range(0, np):
    d = 0
    a = -1
    for j in range(0, n):
        if(obs[j] == -1 and memory[j] >= process[i]):
            x = memory[j]-process[i]
            if(x > d):
                d = x
                a = j
    if(a != -1):
        ps[a] = i
        obs[a] = 0
        frag[a] = memory[a]-process[i]
for i in range(0, n):
    if(ps[i] != -1):
        print("the block", i, "contains procees p", ps[i])
for i in range(0, n):
    print("status of block", i, "is", obs[i])
for i in range(0, n):
    if(obs[i] != -1):
        print("FRAGMENTATION of block", i, "is", frag[i])
s = sum(frag)
print("the sum of fragmentation is", s)
print("the blocks which are empty are")
for i in range(0, n):
    if(obs[i] == -1):
        print(i)
