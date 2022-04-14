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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int hour, minute, c;
    cin >> hour >> minute;
    cin >> c;

    int d = c / 60;
    minute += c % 60;

    if (minute >= 60) {
        d++;
        minute -= 60;
    }

    hour += d;
    if (hour >= 24)
        hour -= 24;

    cout << hour << ' ' << minute << endl;
    return 0;
}
