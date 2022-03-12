#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define endl '\n'
#define sp ' '

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, res;

main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        stack<char> s;
        string str;

        cin >> str;

        int len = str.size();
        bool check = false;

        for (int j = 0; j < len; j++)
        {
            if (s.empty())
            {
                s.push(str[j]);
            }
            else
            {
                if (s.top() == str[j])
                {
                    s.pop();
                }
                else
                {
                    s.push(str[j]);
                }
            }
        }
        if (s.empty())
            res++;
    }

    cout << res << endl;

    return 0;
}
