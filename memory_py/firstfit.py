n = int(input("enter no. of blocks"))
memory = []
print("enter memory blocks storage")
memory = list(map(int, input().split()))
np = int(input("___enter number of processes___"))
print("_________enter process storage______")
process = []
process = list(map(int, input().split()))
obs = [-1]*n
ps = [-1]*n
frag = [0]*n
for i in range(0, np):
    for j in range(0, n):
        if(obs[j] == -1 and memory[j] >= process[i]):
            ps[j] = i
            obs[j] = 0
            frag[j] = memory[j]-process[i]
            break
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
