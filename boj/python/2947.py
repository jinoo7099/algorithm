arr = list(map(int, input().split()))

for i in range(len(arr) - 1):
    for j in range(len(arr) - 1):
        if arr[j] > arr[j+1]:
            arr[j], arr[j+1] = arr[j+1], arr[j]
            for k in arr:
                print(k, end=" ")
            print()
