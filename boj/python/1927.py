from queue import PriorityQueue
import sys
input = sys.stdin.readline

n = int(input())

pq = PriorityQueue()

while n:
    k = int(input())

    if k == 0:
        if pq.empty():
            print(0)
        else:
            print(pq.get())
    else:
        pq.put(k)

    n -= 1
