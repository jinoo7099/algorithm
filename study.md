# 순열

순서를 사용하는 경우, 선택하는 경우
재귀함수로도 바꿔서 풀 수 있다.

## next_permutaion, prev_permutaion

https://twpower.github.io/82-next_permutation-and-prev_permutation

순열을 구하는 STL

next_permutation: 현재 나와 있는 수열에서 인자로 넘어간 범위에 해당하는 다음 순열을 구하고 true를 반환한다. 다음 순열이 없다면(다음에 나온 순열이 순서상 이전 순열보다 작다면) false를 반환.

prev_permutation: 현재 나와 있는 수열에서 인자로 넘어간 범위에 해당하는 이전 순열을 구하고 true를 반환한다. 이전 순열이 없다면(다음에 나온 순열이 순서상 이전 순열보다 크다면) false를 반환.

## 중복제거

```
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end())
```

unique

vector 배열에서 중복되지 않는 원소들을 앞에서부터 채워나가는 함수
배열은 정렬되어있어야한다.

return : 중복된 원소들을 모아둔 뒷부분의 첫주소를 리턴

## size()

https://stackoverflow.com/questions/22868887/error-in-for-loop-when-using-with-vector-size

```
size() returns an unsigned type. With unsigned types, 0 - 1 "underflows" to the maximum value. Since i is less than the maximum possible value of the type it is converted to, the for loop is entered.
```

0 - v.size() unsigned type으로 하면
underflow가 발생하여 이상해진다..
