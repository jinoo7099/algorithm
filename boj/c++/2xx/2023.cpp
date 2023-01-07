#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define X first
#define Y second

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;

bool check(int num) {
    if (num < 2) return false;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void go(int cur, string num) {
    if (num == "0") return;
    if (num != "" && !check(stoi(num))) {
        return;
    }
    if (cur == n) {
        cout << num << endl;
        return;
    }
    for (int i = 0; i <= 9; i++) {
        go(cur + 1, num + to_string(i));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    go(0, "");

    return 0;
}
