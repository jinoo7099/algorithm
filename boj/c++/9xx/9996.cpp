#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int d = s.find("*");

    string s1 = s.substr(0, d);
    string s2 = s.substr(d + 1);

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;

        if (s1.size() + s2.size() > a.size()) {
            cout << "NE" << '\n';
            continue;
        }

        if (a.find(s1) == 0) {
            if (a.substr(a.size() - s2.size()) == s2) {
                cout << "DA" << '\n';
            } else {
                cout << "NE" << '\n';
            }
        } else {
            cout << "NE" << '\n';
        }
    }
    return 0;
}