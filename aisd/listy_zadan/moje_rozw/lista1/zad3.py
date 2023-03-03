# B = [
#     [5, 1, 4], # 1
#     [2, 3], #2
#     [], # 2
#     [4], # 4
#     [], # 5
#     [7, 8, 9, 10], # 6
#     [8], #7
#     [8], # 8
#     [], # 9
#     [], [], # 10, 11
#     [12, 13], # 12
#     [], [] # 13 14
# ]
B = [
    [], # 1
    [0, 7], # 2
    [3, 6], # 3
    [8], # 4
    [7, 1], #5
    [1, 2], # 6
    [8], # 7
    [], []
]

def buduj_min (A):
    n = len(A)
    i = 0
    ret = [i]
    while len(ret) < n:
        #print("# ", i)
        if len(B[i]) > 0:
            m = min(B[i])
            #print("$ ", m)
            B[i].remove(m)
            ret += [m]
            i = m
        else:
            for j in range(0, n):
                if not j in ret:
                    i = j
                    break
            ret += [i]
    
    for j in ret:
        print(j)

buduj_min(B)