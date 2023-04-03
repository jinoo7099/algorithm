#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> ret;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        ret.push_back(temp);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
