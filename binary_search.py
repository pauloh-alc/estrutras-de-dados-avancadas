# Binary-Search - O(log n)
# Iterative and Recursive.

def recursive_binary_search(array, key, begin=0, end=None):
    if end is None:
        end = len(array) - 1
    
    if begin <= end:
        middle = (begin + end) // 2
        
        if key == array[middle]:
            return middle
        elif key < array[middle]:
            return recursive_binary_search(array, key, begin, middle-1)
        else:
            return recursive_binary_search(array, key, middle+1, end)

    return -1

def iterative_binary_search(array, key, begin=0, end=None):
    if end is None:
        end = len(array) - 1
    
    while begin <= end:
        middle = (begin + end) // 2

        if key == array[middle]:
            return middle
        elif key < array[middle]:
            end = middle - 1
        else:
            begin = middle + 1
    return -1


print(recursive_binary_search([1,2,3,4,5,6],6))
print(recursive_binary_search([1],1))
print(recursive_binary_search([1,2,3],4))
print(recursive_binary_search([5,6,7,8,9,10],9))
print(recursive_binary_search([5,6,7,8,9,10],6))

print()

print(iterative_binary_search([1,2,3,4,5,6],6))
print(iterative_binary_search([1],1))
print(iterative_binary_search([1,2,3],4))
print(iterative_binary_search([5,6,7,8,9,10],9))
print(iterative_binary_search([5,6,7,8,9,10],6))
