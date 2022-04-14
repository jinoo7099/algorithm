#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int m, n, res;
int arr[10][10];

void bfs(vector<vector<int>> &v)
{
    queue<pair<int, int>> q;
    int vis[10][10] = {};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 2)
            {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (vis[nx][ny] || v[nx][ny] != 0)
                continue;

            q.push({nx, ny});
            v[nx][ny] = 2;
            vis[nx][ny] = 1;
        }
    }
}

int checkSafeArea(vector<vector<int>> &v)
{
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!v[i][j])
                cnt++;
        }
    }
    return cnt;
}

void makeWall(int cur)
{
    if (cur == 3)
    {
        vector<vector<int>> v(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[i][j] = arr[i][j];
            }
        }

        bfs(v);
        int cnt = checkSafeArea(v);
        res = max(res, cnt);
        return;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][j] = 1;
                makeWall(cur + 1);
                arr[i][j] = 0;
            }
        }
    }
}

main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    makeWall(0);

    cout << res << endl;
    return 0;
}
