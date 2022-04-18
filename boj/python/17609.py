
def check(str):
    l = len(str)

    if str[:l // 2] == str[l - 1: l//2:-1]:
        return True
    elif str[:l // 2] == str[l-1:l-1-l//2:-1]:
        return True

    return False


n = int(input())

while n:
    str = input().strip()
    l = len(str)

    if check(str):
        print(0)
    else:
        left, right = 0, l - 1

        ch = False

        while left < right:
            if str[left] == str[right]:
                left += 1
                right -= 1
            else:
                if str[right] == str[left + 1]:
                    if check(str[left + 1:right + 1]):
                        print(1)
                        break

                if str[left] == str[right - 1]:
                    if check(str[left:right]):
                        print(1)
                        break

                print(2)
                break

    n -= 1
