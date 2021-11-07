# Bubble-Sort:

A = [6,7,8,3,-1,22,6,66]
n = 8

for i in range(0, n):
    for j in range(1, n-1):
        if A[j-1] > A[j]:
            aux = A[j-1]
            A[j-1] = A[j]
            A[j] = aux
    
print(A)

