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

struct Country {
    int num;
    int a;
    int b;
    int c;

    Country() {}

    Country(int n, int a, int b, int c) {
        num = n;
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

bool cmp(Country& c1, Country& c2) {
    if (c1.a != c2.a) return c1.a > c2.a;
    if (c1.b != c2.b) return c1.b > c2.b;
    return c1.c > c2.c;
}

struct Country country[1002];

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        int t, a, b, c;
        scanf("%d %d %d %d", &t, &a, &b, &c);
        country[i] = Country(t, a, b, c);
    }

    sort(country, country + n, cmp);

    int ans;

    for (int i = 0; i < n; i++) {
        if (country[i].num == k) {
            ans = i;
            for (int j = i - 1; j >= 0; j--) {
                if (country[j].a == country[i].a && country[j].b == country[i].b && country[j].c == country[i].c) {
                    ans--;
                } else {
                    break;
                }
            }
            break;
        }
    }

    printf("%d", ans + 1);

    return 0;
}
