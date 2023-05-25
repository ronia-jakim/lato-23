import random

ILOSC = []

N = 99999
i = 0

while i < N:
    i = i+1
    STOL = []
    chlopcy = 0
    for j in range(0, 20):
        if random.randint(0, 9999) % 2 == 1 and chlopcy < 10:
            chlopcy = chlopcy + 1
            STOL.append(0)
        else:
            STOL.append(1)
    n = 0
    for j in range(0, 20):
        if STOL[j] == 1:
            if j > 0 and j < 19:
                if STOL[j-1] == 0 and STOL[j+1] == 0:
                    n = n + 1
            elif j == 0:
                if STOL[j+1] == 0 and STOL[19] == 0:
                    n = n + 1
            elif j >= 19:
                if STOL[j-1] == 0 and STOL[0] == 0:
                    n = n + 1
    ILOSC.append(n)


print(sum(ILOSC) / (N-1))
print(20 / 8)
