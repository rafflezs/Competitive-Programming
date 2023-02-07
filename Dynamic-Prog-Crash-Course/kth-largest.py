import heapq

def kth_largest(arr:list, k):
    arr = [-elem for elem in arr]
    heapq.heapify(arr)
    for i in range(k-1):
        heapq.heappop(arr)
    return -heapq.heappop(arr)


print(kth_largest([4,2,9,7,5,6,7,1,3], 4))