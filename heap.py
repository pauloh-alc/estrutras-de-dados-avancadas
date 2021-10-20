MEMORIA = 10 # variavel representando memoria

heap1 = [95,60,78,39,28,96,70,33] 
heap2 = [30, 60,78,39,28,66,70,33]


def subir(i, T):
    if i % 2 == 0: 
        j = int(i/2) - 1
    else:
        j = int(i/2)

    if j >= 0:
        if T[i] > T[j]:
            aux = T[i]
            T[i] = T[j]
            T[j] = aux
            subir(j, T);


def descer(i, T, n):
    j = 2*i + 1
    
    if  j <= n:
        if j < n:
            if T[j+1] > T[j]:
                j = j + 1
        
        if T[i] < T[j]:
            aux = T[i]
            T[i] = T[j]
            T[j] = aux
            descer(j, T, n)


def inserir(novo, T, n):
    if n < MEMORIA:
        T.append(novo)
        n = n + 1
        subir(n, T)
    else:
        print("Erro: overflow")


def agir(valor):
    print(f'Elemento removido eh: {valor}')


def remover(T,n):
    if n > 0:
        agir(T[0])
        T[0] = T[n]
        n = n - 1
        descer(0, T, n)
    else:
        print("Erro: underflow")


def construir(T, n):
    if n % 2 == 0:
        var = int(n/2) - 1
    else:
        var = int(n/2)

    for i in range(var, -1, -1):
        descer(i, T, n)


def heap_sort(T, n):
    construir(T,n)
    for i in range(n, 1):
        aux = T[0]
        T[0] = T[i]
        T[i] = aux
        descer(0, T, i)


# Realizando testes................:

""" SUBIR """
subir(5,heap1)
print(heap1)

""" DESCER """
descer(0,heap2,7)
print(heap2)

""" INSERIR """
inserir(novo=105, T=heap2, n=7)
inserir(novo=45, T=heap2, n=8)
print(heap2)

""" REMOVER """
remover(T=heap2, n=8)
print(heap2)

""" CONSTRUIR """
vetor1 = [1,2,3,4,5,6,7]
construir(vetor1, 6)
print(vetor1)

""" HEAP SORT"""
vetor2 = [0,2,4,6,8,10,12]
heap_sort(vetor2, 6)
print(vetor2)
