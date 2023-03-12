#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
int fuel;
int arr[22][22];
int vis[22][22];
int taxi_x, taxi_y;
vector<tuple<int, int, int, int>> customers;
bool isEnd;

pair<int, int> findCustomer() {
    // 1. 거리가 가장 짧은 승객
    // 2. 행 번호가 가장 적은 승객
    // 3. 열 번호가 가장 작은 승객

    // int tmp[22][22];
    // memset(tmp, 0, sizeof(tmp));
    memset(vis, 0, sizeof(vis));

    queue<pii> q;
    q.push({taxi_x, taxi_y});
    vis[taxi_x][taxi_y] = 1;

    while (q.size()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (vis[nx][ny] || arr[nx][ny] == -1) continue;

            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    int shortestDis = 1e9;
    int customerNumber = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] > 0 && shortestDis > vis[i][j]) {
                customerNumber = arr[i][j];
                shortestDis = vis[i][j];
            }
        }
    }

    if (customerNumber != -1 && shortestDis == 0) {
        isEnd = true;
    }

    return {customerNumber, shortestDis};
}

void moveTaxi(int customerNumber, int shortestDis) {
    int usedFuel = shortestDis - 1;  // vis 1로 시작했기 때문에
    customerNumber -= 1;
    if (fuel < usedFuel) {
        isEnd = true;
        return;
    }

    // 택시 위치 바꾸기
    fuel -= usedFuel;
    taxi_x = get<0>(customers[customerNumber]);
    taxi_y = get<1>(customers[customerNumber]);
    // 승객 태우기 -> 없애기
    arr[taxi_x][taxi_y] = 0;

    int en_x = get<2>(customers[customerNumber]);
    int en_y = get<3>(customers[customerNumber]);

    //
    memset(vis, 0, sizeof(vis));
    queue<pii> q;
    q.push({taxi_x, taxi_y});
    vis[taxi_x][taxi_y] = 1;
    while (q.size()) {
        auto cur = q.front();
        q.pop();

        if (cur.first == en_x && cur.second == en_y) break;

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (vis[nx][ny] || arr[nx][ny] == -1) continue;

            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    int movedFuel = vis[en_x][en_y] - 1;  // vis 1로 시작했기 때문에

    if (fuel < movedFuel) {
        isEnd = true;
        return;
    }

    taxi_x = en_x;
    taxi_y = en_y;

    fuel -= movedFuel;
    // 충전
    fuel += movedFuel * 2;
}

void solve() {
    int customerNumber, shortestDis;
    tie(customerNumber, shortestDis) = findCustomer();
    if (isEnd) return;

    moveTaxi(customerNumber, shortestDis);
    if (isEnd) return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> fuel;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) {
                arr[i][j] = -1;
            }
        }
    }

    cin >> taxi_x >> taxi_y;

    for (int i = 1; i <= m; i++) {
        int st_r, st_c, en_r, en_c;
        cin >> st_r >> st_c >> en_r >> en_c;

        arr[st_r][st_c] = i;
        customers.push_back({st_r, st_c, en_r, en_c});
    }

    for (int i = 0; i < m; i++) {
        solve();

        if (isEnd) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << fuel << endl;
    return 0;
}
