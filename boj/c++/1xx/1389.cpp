#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
int arr[102][102];
vector<pair<int, int>> res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> dist(102, -1);

        queue<int> q;
        q.push(i);
        dist[i] = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int j = 1; j <= n; j++) {
                if (arr[cur][j] == 0 || dist[j] != -1) continue;
                dist[j] = dist[cur] + 1;
                q.push(j);
            }
        }

        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += dist[j];
        }
        res.push_back({sum, i});
    }

    sort(res.begin(), res.end());

    cout << res[0].second << endl;
    return 0;
}

/*
    res 배열에 넣을필요 없이 변수 2개 써서 min 값 찾으면 될듯
*/