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

vector<int> ans;

// i 번째 전 까지 반복이 된다.
/*
    a b c a b d
=>  0 0 0 1 2 0
    a 는 1번째 인덱스 전까지 반복된다
    b 는 2번째 인덱스 전까지 반복된다.
    인덱스는 0부터 시작
*/
vector<int> makeTable(string pattern) {
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j = 0;

    for (int i = 1; i < patternSize; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

void kmp(string s, string p) {
    vector<int> table = makeTable(p);

    int n = s.size();
    int m = p.size();
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = table[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(i - m + 1);
                j = table[j];
            } else {
                j++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str1, str2;
    cin >> str1 >> str2;

    kmp(str1, str2);

    if (ans.empty()) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}
