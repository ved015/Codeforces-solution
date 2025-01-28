from collections import deque

def solution(array, k):
    d = deque(array)
    elimination_order = []
    
    while d:
        d.rotate(1 - k)
        item = d.popleft()
        elimination_order.append(item)
    
    return elimination_order


n = int(input())

k = 2

array = list(range(1, n + 1))

ans = solution(array, k)
print(*ans)
