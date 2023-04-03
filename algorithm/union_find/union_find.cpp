#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

// 부모 노드를 찾는 함수
int getParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

// 같은 부모를 가지는지 확인 (같이 그래프에 있는지)
int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int parent[11];
    for (int i = 1; i <= 10; i++) {
        parent[i] = i;
    }

    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);

    cout << "1과 5는 연결되어 있나요?" << endl;
    cout << findParent(parent, 1, 5);

    return 0;
}

/*
    Union find - 합집합 찾기
    서로소(Disjoint-Set) 알고리즘이라고 함
    합집합을 찾는것은 서로소를 찾는 것과 흡사함

    여러 개의 노드가 존재할 때 두개의 노드를 선택해서,
    현재 이 두 노드가 서로 같은 그래프에 속하는지 판별하는 알고리즘

    //

    모든 노드는 부모 노드를 가르키는 값을 가짐
    처음에는 모든노드가 자기 자신이 부모노드 이기 떄문에 자기를 가르킴

    Union
    부모를 합칠 때는 일반적으로 작은 값 쪽으로 합침
    재귀 함수를 통해서 부모노드를 고쳐나감
    ex) 1-2, 2-3 일떄 1-3이 같은 집합에 속하는지 확인

    Find
    두 개의 노드의 부모 노드를 확인하여 현재 같은 집합이 속하는지 확인


*/