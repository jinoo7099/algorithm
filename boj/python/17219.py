import sys

input = sys.stdin.readline
n, m = map(int, input().split())

dic = {}
for _ in range(n):
    site, pwd = input().split()
    dic[site] = pwd

for _ in range(m):
    site = input()
    print(dic[site.strip()])
