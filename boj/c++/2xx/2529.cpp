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

bool check(vector<int>& perm, vector<char> ops) {
    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == '<' && !(perm[i] < perm[i + 1])) {
            return false;
        }
        if (ops[i] == '>' && !(perm[i] > perm[i + 1])) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    vector<int> small(k + 1);
    vector<int> big(k + 1);
    for (int i = 0; i < k + 1; i++) {
        small[i] = i;
        big[i] = 9 - i;
    }

    vector<char> ops(k);

    for (int i = 0; i < k; i++) {
        cin >> ops[i];
    }

    do {
        if (check(small, ops)) {
            break;
        }
    } while (next_permutation(small.begin(), small.end()));
    do {
        if (check(big, ops)) {
            break;
        }
    } while (prev_permutation(big.begin(), big.end()));

    for (int i = 0; i < k + 1; i++) {
        cout << big[i];
    }
    cout << endl;
    for (int i = 0; i < k + 1; i++) {
        cout << small[i];
    }
    cout << endl;

    return 0;
}
