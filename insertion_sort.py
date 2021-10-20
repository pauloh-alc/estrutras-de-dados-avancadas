A = [4,1,8,9,7,3,0,6]
#    0 1 2 3 4 5 6 7
n = len(A) # n = 8

A = [9,8,7,6,5,4,3,2,1];
n = 9
print(f'Lista antiga: {A}')

for j in range(1, n):
    chave = A[j]

    i = j - 1
    while A[i] > chave and i >= 0:
        A[i+1] = A[i]
        i = i - 1
        print(f'j={j}')
    print()

    A[i+1] = chave

print(f'Lista ordenada: {A}')
