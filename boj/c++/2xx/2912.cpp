#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

struct Dwarf {
    int left;
    int right;
    int idx;

    Dwarf(int l, int r, int i) {
        left = l;
        right = r;
        idx = i;
    }
};

int arr[300003];
int cnt[10002];
int n, c, m, k;
int low, high;

vector<Dwarf> picture;
pair<string, int> res[10002];

bool cmp(const Dwarf& p1, const Dwarf& p2) {
    if (p1.left / k != p2.left / k) return (p1.left / k) < (p2.left / k);
    return p1.right < p2.right;
}

void solve() {
    low = 1, high = n;
    for (int i = 0; i < m; i++) {
        int st = picture[i].left;
        int end = picture[i].right;

        while (st != low) {
            if (low < st) {
                cnt[arr[low]]--;
                low++;
            } else if (low > st) {
                low--;
                cnt[arr[low]]++;
            }
        }

        while (end != high) {
            if (high < end) {
                high++;
                cnt[arr[high]]++;
            } else if (high > end) {
                cnt[arr[high]]--;
                high--;
            }
        }

        int kk = high - low + 1;

        bool check = false;
        for (int j = 1; j <= c; j++) {
            if (cnt[j] > kk / 2) {
                res[picture[i].idx].first = "yes";
                res[picture[i].idx].second = j;
                check = true;
                break;
            }
        }

        if (!check) {
            res[picture[i].idx].first = "no";
            res[picture[i].idx].second = 0;
        }
    }

    // get answer
    for (int i = 0; i < m; i++) {
        cout << res[i].first << ' ';
        if (res[i].second)
            cout << res[i].second;
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;

    k = sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    cin >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        picture.push_back(Dwarf(a, b, i));
    }

    sort(picture.begin(), picture.end(), cmp);

    solve();

    return 0;
}